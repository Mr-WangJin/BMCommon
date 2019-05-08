#pragma once

#include "BMGlobal.h"
#include <QVector>
#include <QJsonObject>

namespace BMCOMMON 
{
	/**
	 *	����GSPModel
	 *  @path : �ļ�·����ַ
	 */
	BIMCOMMON_EXPORT void LoadGSPModel(GSPModel & model, const QString &path, bool simpleDataIntf = false, bool readOnly = false);

	/** 
	 *	����GSPģ��
	 */
	BIMCOMMON_EXPORT void SaveGSPModel(GSPModel & model, const QString &fileName, bool compressData = true, bool encryptData = true);

	/** 
	 *	��ȡ��ָ���Լ�������ֶ���
	 */
	BIMCOMMON_EXPORT void GetForeignToMineField(GSPTable table, QStringList & toMineList);

	/** 
	 *	��table�����ڵ�Model�У��ҵ�table�µ������ֱ�����
	 */
	BIMCOMMON_EXPORT void GetTableChildList(GSPTable table, QStringList& childList);

	enum CONVER_GSPTABLE_TTYPE
	{
		FIELD_NAME,
		FIELD_NAME_FIRST_LOWERCASE,
		ALIAS_NAME
	};
	/**
	*	��GSPTable����ת��ΪJson����
	*	Json��ʽΪ��tableName :{[{}{}{}{}]}
	*	@type : ת��ΪJsonʱʹ�õ�keyֵ��Դ���ͣ�
	*  FIELD_NAME ��ʹ���ֶ���
	*	FIELD_NAME_FIRST_LOWERCASE ��ʹ���ֶ���������ĸСд
	*	ALIAS_NAME ���ֶα���ȥ���»��ߣ��������Ϊ�գ�ʹ��FIELD_NAME_FIRST_LOWERCASE����
	*/
	void ConvertGSPTableToJsonObject(GSPTable t, QJsonObject & obj, CONVER_GSPTABLE_TTYPE type);



// 	/** 
// 	 *	��String �����ֶε���������ת������Ӧ����
// 	 */
// 	BIMCOMMON_EXPORT void GetForeignToMineField(GSPTable table, QStringList & toMineList);


/**
*	�����࣬��Ҫʹ���߰���֮���������ϵ�����Ⱥ󿽱���
*	ֻ֧�ֱ����������ΪUINT64
*/
	class BMTableCopy
	{
	public:
		BMTableCopy(bool isCopyPrimaryID = false);
		~BMTableCopy();

		/**
		 *	��������ƥ����������ֶΣ����п���,֧�ֵ����ӽṹ
		 *  @filter : ���ڹ���Դ���ݱ�
		 *	@unNormForeignFields : ������ֶε�����ֶΣ�ָ�������������ֶ�
		 */
		GSPRecordList batchCloneTable(GSPTable fromTable, GSPTable toTable, const QStringList & unNormForeignFields, const QString & filter);

		/**
		 *	��һ�ű��п���������һ�ű���
		 *	@isCascade : �Ƿ������°��ӽڵ�һ�𿽱���Ĭ��Ϊfalse
		 */
		GSPRecord copyRecordToTable(GSPRecord fromR, GSPTable toTable, const bool &isCascadeDown = false);

		/**
		 *	�����Ҫ����ԭʼ�����������õ�ǰԭʼ�����ֶ���������ԭʼ����
		 *	����ԭ���������ֶ�����ֻ�е�isCopyPrimaryIDΪfalse��ʱ���������
		 */
		void setOriginPrimaryField(const QString & field);

		/**
		 *	��ȡ����IDӳ��
		 */
		QMap<quint64, quint64> getPrimaryIdMaping();

		/**
		 *	�������IDӳ��
		 */
		void clearPrimaryIDMaping();

	private:
		void setIsCopyPrimaryID(bool isCopyPrimaryID);

		/**
		 *	��¡������¼�����������Ӽ�¼
		 *  @FromIdx_ToIdx : Դ�����ֶ�����������Ŀ���ֶ�����
		 *  @toMineForeignName : ָ���Լ�����������
		 */
		void CloneRecordToRecord(GSPRecord fromR, const std::vector<std::pair<int, int>> & FromIdx_ToIdx, QString toMineForeignName, GSPTable toTable);

	private:
		bool					m_isCopyPrimaryID;
		QString					m_OriginPrimaryField;

		QStringList				m_unNormForeignFields;			//����������ֶ�

		QMap<quint64, quint64>	m_primaryIDMaping;

		GSPRecordList			m_tempResult;
	};


}



