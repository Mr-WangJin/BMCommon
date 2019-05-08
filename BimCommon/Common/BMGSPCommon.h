#pragma once

#include "BMGlobal.h"
#include <QVector>
#include <QJsonObject>

namespace BMCOMMON 
{
	/**
	 *	加载GSPModel
	 *  @path : 文件路径地址
	 */
	BIMCOMMON_EXPORT void LoadGSPModel(GSPModel & model, const QString &path, bool simpleDataIntf = false, bool readOnly = false);

	/** 
	 *	保存GSP模型
	 */
	BIMCOMMON_EXPORT void SaveGSPModel(GSPModel & model, const QString &fileName, bool compressData = true, bool encryptData = true);

	/** 
	 *	获取表指向自己的外键字段名
	 */
	BIMCOMMON_EXPORT void GetForeignToMineField(GSPTable table, QStringList & toMineList);

	/** 
	 *	在table表所在的Model中，找到table下的所有字表名称
	 */
	BIMCOMMON_EXPORT void GetTableChildList(GSPTable table, QStringList& childList);

	enum CONVER_GSPTABLE_TTYPE
	{
		FIELD_NAME,
		FIELD_NAME_FIRST_LOWERCASE,
		ALIAS_NAME
	};
	/**
	*	将GSPTable数据转换为Json数据
	*	Json格式为：tableName :{[{}{}{}{}]}
	*	@type : 转换为Json时使用的key值来源类型，
	*  FIELD_NAME ：使用字段名
	*	FIELD_NAME_FIRST_LOWERCASE ：使用字段名，首字母小写
	*	ALIAS_NAME ：字段别名去下下划线，如果别名为空，使用FIELD_NAME_FIRST_LOWERCASE类型
	*/
	void ConvertGSPTableToJsonObject(GSPTable t, QJsonObject & obj, CONVER_GSPTABLE_TTYPE type);



// 	/** 
// 	 *	把String 按照字段的数据类型转换成相应类型
// 	 */
// 	BIMCOMMON_EXPORT void GetForeignToMineField(GSPTable table, QStringList & toMineList);


/**
*	表拷贝类，需要使用者按表之间的依赖关系进行先后拷贝表
*	只支持表主键，外键为UINT64
*/
	class BMTableCopy
	{
	public:
		BMTableCopy(bool isCopyPrimaryID = false);
		~BMTableCopy();

		/**
		 *	表拷贝，会匹配两个表的字段，进行拷贝,支持单表父子结构
		 *  @filter : 用于过滤源数据表
		 *	@unNormForeignFields : 非外键字段的外键字段，指向其它表的外键字段
		 */
		GSPRecordList batchCloneTable(GSPTable fromTable, GSPTable toTable, const QStringList & unNormForeignFields, const QString & filter);

		/**
		 *	从一张表中拷贝到另外一张表中
		 *	@isCascade : 是否级联向下把子节点一起拷贝，默认为false
		 */
		GSPRecord copyRecordToTable(GSPRecord fromR, GSPTable toTable, const bool &isCascadeDown = false);

		/**
		 *	如果需要保存原始主键，可设置当前原始主键字段用来保存原始主键
		 *	设置原数据主键字段名，只有当isCopyPrimaryID为false的时候才起作用
		 */
		void setOriginPrimaryField(const QString & field);

		/**
		 *	获取主键ID映射
		 */
		QMap<quint64, quint64> getPrimaryIdMaping();

		/**
		 *	清空主键ID映射
		 */
		void clearPrimaryIDMaping();

	private:
		void setIsCopyPrimaryID(bool isCopyPrimaryID);

		/**
		 *	克隆单条记录，级联拷贝子记录
		 *  @FromIdx_ToIdx : 源数据字段索引拷贝到目标字段索引
		 *  @toMineForeignName : 指向自己表的外键名称
		 */
		void CloneRecordToRecord(GSPRecord fromR, const std::vector<std::pair<int, int>> & FromIdx_ToIdx, QString toMineForeignName, GSPTable toTable);

	private:
		bool					m_isCopyPrimaryID;
		QString					m_OriginPrimaryField;

		QStringList				m_unNormForeignFields;			//非正常外键字段

		QMap<quint64, quint64>	m_primaryIDMaping;

		GSPRecordList			m_tempResult;
	};


}



