<?xml version="1.0" encoding="utf-8" ?>
<GSPModel GSPModelNode="True" DataFormatVersion="2.5.12" BizVersion="" xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">
    <a:Version>2.5.12</a:Version>
    <a:Name>GSPModel</a:Name>
    <a:Mode>2</a:Mode>
    <c:Databases>
        <o:Database>
            <a:Name>DB</a:Name>
            <c:Tables>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>edo</a:Name>
                        <a:DisplayName>图元</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,SQLITE</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>parent_id</a:FieldName>
                                <a:AliasName>parentId</a:AliasName>
                                <a:DisplayName>父图元ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>element_type_id</a:FieldName>
                                <a:AliasName>elementTypeId</a:AliasName>
                                <a:DisplayName>构件类型</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>floor_id</a:FieldName>
                                <a:AliasName>floorId</a:AliasName>
                                <a:DisplayName>楼层ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                    <o:ExtPropDef>
                                        <a:Code>MasterTableName</a:Code>
                                        <a:Value>floor</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>system_id</a:FieldName>
                                <a:AliasName>systemId</a:AliasName>
                                <a:DisplayName>系统ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                    <o:ExtPropDef>
                                        <a:Code>MasterTableName</a:Code>
                                        <a:Value>system</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_revision_id</a:FieldName>
                                <a:AliasName>fileRevisionId</a:AliasName>
                                <a:DisplayName>文件块ID</a:DisplayName>
                                <a:Remark>=ModelFileRevisionID</a:Remark>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>default_material_id</a:FieldName>
                                <a:AliasName>defaultMaterialId</a:AliasName>
                                <a:DisplayName>默认材质</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>unique_key</a:FieldName>
                                <a:AliasName>uniqueKey</a:AliasName>
                                <a:DisplayName>与外部做对应的唯一ID</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>volume</a:FieldName>
                                <a:DisplayName>体积</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:DefaultExpr>-1</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>axis_position</a:FieldName>
                                <a:AliasName>axisPosition</a:AliasName>
                                <a:DisplayName>轴网坐标</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_bar_attached</a:FieldName>
                                <a:AliasName>isBarAttached</a:AliasName>
                                <a:DisplayName>是否有钢筋几何</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>bar_3d_offset</a:FieldName>
                                <a:AliasName>bar3dOffset</a:AliasName>
                                <a:DisplayName>钢筋三维偏移量</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>properties</a:FieldName>
                                <a:DisplayName>属性</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>properties_edited</a:FieldName>
                                <a:AliasName>propertiesEdited</a:AliasName>
                                <a:DisplayName>修改过的属性</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>quantities</a:FieldName>
                                <a:DisplayName>工程量</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>model_file_group</a:Name>
                        <a:DisplayName>模型文件分组</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>parent_id</a:FieldName>
                                <a:AliasName>parentId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>model_file_group</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>model_file</a:Name>
                        <a:DisplayName>模型文件</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>group_id</a:FieldName>
                                <a:AliasName>groupId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>model_file_group</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_name</a:FieldName>
                                <a:AliasName>fileName</a:AliasName>
                                <a:DisplayName>文件名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>building_name</a:FieldName>
                                <a:AliasName>buildingName</a:AliasName>
                                <a:DisplayName>单体名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:CalcExpr>concat(&apos;,&apos;,model_file_building.building_name[model_file_id = ?id])</a:CalcExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>elevation_system</a:FieldName>
                                <a:AliasName>elevationSystem</a:AliasName>
                                <a:DisplayName>标高体系</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:EnumNames>1=建筑标高|2=结构标高</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>file_type</a:FieldName>
                                <a:AliasName>fileType</a:AliasName>
                                <a:DisplayName>文件类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1=GCL|2=GGJ|3=GQI|4=GJG|5=MagiCAD-IFC|6=RevitMEP-IFC|7=Tekla-IFC|8=GSL|9=Revit|10=Revit-MEP|11=Revit-CE|12=SketchUp|13=ArchiCAD|14=GMJ|15=GTJ|16=GMA|100=Other</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>update_date</a:FieldName>
                                <a:AliasName>updateDate</a:AliasName>
                                <a:DisplayName>更新日期</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>previous_revision_id</a:FieldName>
                                <a:AliasName>previousRevisionId</a:AliasName>
                                <a:DisplayName>前一版本</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>current_revision_id</a:FieldName>
                                <a:AliasName>currentRevisionId</a:AliasName>
                                <a:DisplayName>当前版本</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>transformation</a:FieldName>
                                <a:DisplayName>变换矩阵</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>model_file_revision</a:Name>
                        <a:DisplayName>模型文件修订</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>model_file_id</a:FieldName>
                                <a:AliasName>modelFileId</a:AliasName>
                                <a:DisplayName>模型文件ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>model_file</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>file_id</a:FieldName>
                                <a:AliasName>fileId</a:AliasName>
                                <a:DisplayName>文件ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>file</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>bimface_file_id</a:FieldName>
                                <a:AliasName>bimfaceFileId</a:AliasName>
                                <a:DisplayName>BIMFaca文件ID</a:DisplayName>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_revision</a:FieldName>
                                <a:AliasName>fileRevision</a:AliasName>
                                <a:DisplayName>修订号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>pmi</a:FieldName>
                                <a:DisplayName>变更号</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_name</a:FieldName>
                                <a:AliasName>fileName</a:AliasName>
                                <a:DisplayName>文件名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_current</a:FieldName>
                                <a:AliasName>isCurrent</a:AliasName>
                                <a:DisplayName>当前标记</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>true</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>update_date</a:FieldName>
                                <a:AliasName>updateDate</a:AliasName>
                                <a:DisplayName>更新日期</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>修订说明</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>system</a:Name>
                        <a:DisplayName>系统字典</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>parent_id</a:FieldName>
                                <a:AliasName>，</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>system</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>specialty_id</a:FieldName>
                                <a:AliasName>specialtyId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>specialty</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>系统名称不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>&apos;系统名称&apos;</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>building</a:Name>
                        <a:DisplayName>单体信息</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>单体ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>单体名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>单体名称不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>&apos;单体&apos;</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>单体编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>单体编码不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>&apos;单体编码&apos;</a:DefaultExpr>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>area</a:FieldName>
                                <a:DisplayName>建筑规模</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>3</a:Precision>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>height</a:FieldName>
                                <a:DisplayName>建筑高度</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>2</a:Precision>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>structure_type</a:FieldName>
                                <a:AliasName>structureType</a:AliasName>
                                <a:DisplayName>结构形式</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>9</a:DefaultExpr>
                                <a:EnumNames>1=框架结构|2=框架-剪力墙结构|3=剪力墙结构|4=框支-剪力墙结构|5=框架-核心筒结构|6=筒中筒结构|7=单层厂房|8=砖混结构|9=其他</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>ground_floor</a:FieldName>
                                <a:AliasName>groundFloor</a:AliasName>
                                <a:DisplayName>地上层数</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>地上层数不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:Constraint>ground_floor &gt;= 0</a:Constraint>
                                <a:ConstraintErrMsg>地上层数必须为大于等于0的整数</a:ConstraintErrMsg>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>underground_floor</a:FieldName>
                                <a:AliasName>undergroundFloor</a:AliasName>
                                <a:DisplayName>地下层数</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>地下层数不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>0</a:DefaultExpr>
                                <a:Constraint>underground_floor&gt;=0</a:Constraint>
                                <a:ConstraintErrMsg>地下层数必须为大于等于0的整数</a:ConstraintErrMsg>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>顺序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_locked</a:FieldName>
                                <a:AliasName>isLocked</a:AliasName>
                                <a:DisplayName>是否锁定</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>floor</a:Name>
                        <a:DisplayName>楼层信息</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>building_id</a:FieldName>
                                <a:AliasName>buildingId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>building</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>楼层编码不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>&apos;楼层编码&apos;</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                                <a:RequiredErrMsg>楼层名称不能为空</a:RequiredErrMsg>
                                <a:DefaultExpr>&apos;楼层名称&apos;</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>structural_height</a:FieldName>
                                <a:AliasName>structuralHeight</a:AliasName>
                                <a:DisplayName>结构层高</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>3</a:Precision>
                                <a:DefaultExpr>3</a:DefaultExpr>
                                <a:IsIndexField>True</a:IsIndexField>
                                <a:Constraint>structural_height&gt;0</a:Constraint>
                                <a:ConstraintErrMsg>层高必须为大于0的数值</a:ConstraintErrMsg>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>architectural_height</a:FieldName>
                                <a:AliasName>architecturalHeight</a:AliasName>
                                <a:DisplayName>建筑层高</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>3</a:Precision>
                                <a:DefaultExpr>3</a:DefaultExpr>
                                <a:Constraint>architectural_height&gt;0</a:Constraint>
                                <a:ConstraintErrMsg>层高必须为大于等于0的数值</a:ConstraintErrMsg>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>structural_elevation</a:FieldName>
                                <a:AliasName>structuralElevation</a:AliasName>
                                <a:DisplayName>结构标高</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>3</a:Precision>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>architectural_elevation</a:FieldName>
                                <a:AliasName>architecturalElevation</a:AliasName>
                                <a:DisplayName>建筑标高</a:DisplayName>
                                <a:DataType>8</a:DataType>
                                <a:Precision>3</a:Precision>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>floor_type</a:FieldName>
                                <a:AliasName>floorType</a:AliasName>
                                <a:DisplayName>楼层类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:EnumNames>1=首层|2=基础层|3=其它层</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>顺序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_locked_architectural_elevation</a:FieldName>
                                <a:AliasName>isLockedArchitecturalElevation</a:AliasName>
                                <a:DisplayName>锁定建筑标高</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_locked_structural_elevation</a:FieldName>
                                <a:AliasName>isLockedStructuralElevation</a:AliasName>
                                <a:DisplayName>锁定结构标高</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_locked_architectural_height</a:FieldName>
                                <a:AliasName>isLockedArchitecturalHeight</a:AliasName>
                                <a:DisplayName>锁定建筑层高</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_locked_structural_height</a:FieldName>
                                <a:AliasName>isLockedStructuralHeight</a:AliasName>
                                <a:DisplayName>锁定结构层高</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>model_file_building</a:Name>
                        <a:DisplayName>模型文件单体</a:DisplayName>
                        <a:Catalog>模型</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>model_file_id</a:FieldName>
                                <a:AliasName>modelFileId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>model_file</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>building_id</a:FieldName>
                                <a:AliasName>buildingId</a:AliasName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>building</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="5">
                                <a:FieldName>building_name</a:FieldName>
                                <a:AliasName>buildingName</a:AliasName>
                                <a:Remark>这个字段还不能干掉，model_file表中的building_name用了这个字段</a:Remark>
                                <a:StrLength>255</a:StrLength>
                                <a:CalcExpr>~building_id.name</a:CalcExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>TableVersion</a:Name>
                        <a:DisplayName>表版本</a:DisplayName>
                        <a:Catalog>表同步</a:Catalog>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>TableVersionID</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>TableName</a:FieldName>
                                <a:DisplayName>表名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>RemoteTableName</a:FieldName>
                                <a:DisplayName>服务器表名</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LocalVersion</a:FieldName>
                                <a:DisplayName>本地版本号</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>max_record_revision</a:FieldName>
                                <a:AliasName>maxRecordRevision</a:AliasName>
                                <a:DisplayName>记录最大版本号</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>RemoteType</a:FieldName>
                                <a:DisplayName>远端类型</a:DisplayName>
                                <a:Remark>全量获取没有表版本号</a:Remark>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1 = CloudT|2 = BIM5D|3 = Cost</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>RemoteVersion</a:FieldName>
                                <a:DisplayName>远端版本号</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>SyncType</a:FieldName>
                                <a:DisplayName>同步类型</a:DisplayName>
                                <a:Remark>全量获取没有表版本号</a:Remark>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1 = FullType|2 = IncrementType</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>ToRemoteFieldType</a:FieldName>
                                <a:DisplayName>对应后端的字段</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>3</a:DefaultExpr>
                                <a:EnumNames>1 = Alias_Type|2 = Customize_Type|3 = FieldName</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>FullSyncType</a:FieldName>
                                <a:DisplayName>哈希类型</a:DisplayName>
                                <a:Remark>全量获取没有表版本号</a:Remark>
                                <a:DataType>2</a:DataType>
                                <a:Required>True</a:Required>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1 = NoHash|2 = WidthHash</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LocalFullHashValue</a:FieldName>
                                <a:DisplayName>本地全量哈希值</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>RemoteFullHashValue</a:FieldName>
                                <a:DisplayName>远端全量哈希值</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>IsGZip</a:FieldName>
                                <a:DisplayName>数据是否压缩</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData>
                        <c:Records Format="1">
                            <o:Record>1,&apos;edo&apos;,&apos;edo&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>2,&apos;model_file_group&apos;,&apos;model_file_group&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>3,&apos;model_file&apos;,&apos;model_file&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>4,&apos;model_file_revision&apos;,&apos;model_file_revision&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>5,&apos;building&apos;,&apos;building&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>6,&apos;floor&apos;,&apos;floor&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>7,&apos;model_file_building&apos;,&apos;model_file_building&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>8,&apos;segment_group&apos;,&apos;segment_group&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>9,&apos;segment&apos;,&apos;segment&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>10,&apos;segment_element&apos;,&apos;segment_element&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>11,&apos;segment_floor&apos;,&apos;segment_floor&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>12,&apos;segment_edo&apos;,&apos;segment_edo&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>13,&apos;sliced_edo&apos;,&apos;sliced_edo&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                            <o:Record>14,&apos;file&apos;,&apos;file&apos;,0,0,1,0,2,3,1,,,0</o:Record>
                        </c:Records>
                    </o:TableData>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>ToRemoteField</a:Name>
                        <a:DisplayName>对应远端字段</a:DisplayName>
                        <a:Catalog>表同步</a:Catalog>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>ToRemoteFieldID</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>TableVersionID</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:LookupKind>1</a:LookupKind>
                                <a:LookupTableName>TableVersion</a:LookupTableName>
                                <a:LookupResult>TableVersionID</a:LookupResult>
                                <a:LookupDescription>TableName</a:LookupDescription>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>TableVersion</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>LocalFieldName</a:FieldName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>RemoteFieldName</a:FieldName>
                                <a:StrLength>255</a:StrLength>
                                <a:Required>True</a:Required>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>Description</a:FieldName>
                                <a:DisplayName>字段描述</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>FieldType</a:FieldName>
                                <a:DisplayName>字段类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1 = OtherKey|2 = PrimaryKey|3 = ForeignToMine|4 = ForeignToOther</a:EnumNames>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>segment_group</a:Name>
                        <a:DisplayName>流水段分组</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>parent_id</a:FieldName>
                                <a:AliasName>parentId</a:AliasName>
                                <a:DisplayName>本表外键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>segment_group</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>specialty_id</a:FieldName>
                                <a:AliasName>specialtyId</a:AliasName>
                                <a:DisplayName>专业</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>specialty</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>building_id</a:FieldName>
                                <a:AliasName>buildingId</a:AliasName>
                                <a:DisplayName>单体</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>building</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>floor_id</a:FieldName>
                                <a:AliasName>floorId</a:AliasName>
                                <a:DisplayName>楼层</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>floor</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>type</a:FieldName>
                                <a:DisplayName>分组类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:EnumNames>1=Building|2=Specialty|3=Floor|4=None</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>segment</a:Name>
                        <a:DisplayName>流水段</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>segment_group_id</a:FieldName>
                                <a:AliasName>segmentGroupId</a:AliasName>
                                <a:DisplayName>流水分组</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>segment_group</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>building_id</a:FieldName>
                                <a:AliasName>buildingId</a:AliasName>
                                <a:DisplayName>单体</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>building</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>specialty_id</a:FieldName>
                                <a:AliasName>specialtyId</a:AliasName>
                                <a:DisplayName>专业</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>specialty</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>start_floor_id</a:FieldName>
                                <a:AliasName>startFloorId</a:AliasName>
                                <a:DisplayName>起始楼层</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>floor</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>end_floor_id</a:FieldName>
                                <a:AliasName>endFloorId</a:AliasName>
                                <a:DisplayName>终止楼层</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>start_elevation</a:FieldName>
                                <a:AliasName>startElevation</a:AliasName>
                                <a:DisplayName>起始标高</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>end_elevation</a:FieldName>
                                <a:AliasName>endElevation</a:AliasName>
                                <a:DisplayName>终止标高</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>position_type</a:FieldName>
                                <a:AliasName>positionType</a:AliasName>
                                <a:DisplayName>位置类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>2</a:DefaultExpr>
                                <a:EnumNames>1=按楼层|2=自定义</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>dimension_type</a:FieldName>
                                <a:AliasName>dimensionType</a:AliasName>
                                <a:DisplayName>维度类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1=按楼层构件类型|2=按系统</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>color</a:FieldName>
                                <a:DisplayName>颜色</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>line_width</a:FieldName>
                                <a:AliasName>lineWidth</a:AliasName>
                                <a:DisplayName>线宽</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>2</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>segment_line_type</a:FieldName>
                                <a:AliasName>segmentLineType</a:AliasName>
                                <a:DisplayName>线框类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:EnumNames>1=实线|2=点|3=线段|4=点划线</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>task_status</a:FieldName>
                                <a:AliasName>taskStatus</a:AliasName>
                                <a:DisplayName>任务状态</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                                <a:EnumNames>0=未开始|1=进行中|2=已完成|3=未定义1|4=未定义2|5=未定义3|6=未定义4</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>task_deviation</a:FieldName>
                                <a:AliasName>taskDeviation</a:AliasName>
                                <a:DisplayName>任务偏差</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>plan_start_time</a:FieldName>
                                <a:AliasName>planStartTime</a:AliasName>
                                <a:DisplayName>计划开始时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>plan_finish_time</a:FieldName>
                                <a:AliasName>planFinishTime</a:AliasName>
                                <a:DisplayName>计划结束时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>real_start_time</a:FieldName>
                                <a:AliasName>realStartTime</a:AliasName>
                                <a:DisplayName>实际开始时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>real_finis_time</a:FieldName>
                                <a:AliasName>realFinisTime</a:AliasName>
                                <a:DisplayName>实际结束时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_show_line</a:FieldName>
                                <a:AliasName>isShowLine</a:AliasName>
                                <a:DisplayName>是否显示线框</a:DisplayName>
                                <a:DataType>1</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_need_relink</a:FieldName>
                                <a:AliasName>isNeedRelink</a:AliasName>
                                <a:DisplayName>需要调整标记</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>false</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_related_edo</a:FieldName>
                                <a:AliasName>isRelatedEdo</a:AliasName>
                                <a:DisplayName>是否关联图元</a:DisplayName>
                                <a:DataType>1</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_related_task</a:FieldName>
                                <a:AliasName>isRelatedTask</a:AliasName>
                                <a:DisplayName>是否关联任务</a:DisplayName>
                                <a:DataType>1</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>order_no</a:FieldName>
                                <a:AliasName>orderNo</a:AliasName>
                                <a:DisplayName>序号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>segment_element</a:Name>
                        <a:DisplayName>流水段关联构件类型</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>segment_id</a:FieldName>
                                <a:AliasName>segmentId</a:AliasName>
                                <a:DisplayName>流水段</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>segment</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>element_type_id</a:FieldName>
                                <a:AliasName>elementTypeId</a:AliasName>
                                <a:DisplayName>构件类型ID</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>segment_floor</a:Name>
                        <a:DisplayName>流水段关联楼层</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>segment_id</a:FieldName>
                                <a:AliasName>segmentId</a:AliasName>
                                <a:DisplayName>流水段</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>segment</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>floor_id</a:FieldName>
                                <a:AliasName>floorId</a:AliasName>
                                <a:DisplayName>楼层外键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>floor</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>segment_edo</a:Name>
                        <a:DisplayName>流水段关联图元</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,SQLITE</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>segment_id</a:FieldName>
                                <a:AliasName>segmentId</a:AliasName>
                                <a:DisplayName>流水段</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>segment</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>edo_id</a:FieldName>
                                <a:AliasName>edoId</a:AliasName>
                                <a:DisplayName>图元ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>edo</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>sliced_edo_id</a:FieldName>
                                <a:AliasName>slicedEdoId</a:AliasName>
                                <a:DisplayName>切割ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>sliced_edo</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>sliced_edo</a:Name>
                        <a:DisplayName>切割图元</a:DisplayName>
                        <a:Catalog>流水段</a:Catalog>
                        <a:ExtData>MYSQL,SQLITE</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>edo_id</a:FieldName>
                                <a:AliasName>edoId</a:AliasName>
                                <a:DisplayName>图元ID</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>edo</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>slice_type</a:FieldName>
                                <a:AliasName>sliceType</a:AliasName>
                                <a:DisplayName>切割类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>1</a:DefaultExpr>
                                <a:IsIndexField>True</a:IsIndexField>
                                <a:EnumNames>1=Slice|2=Remain</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>origin_volume</a:FieldName>
                                <a:AliasName>originVolume</a:AliasName>
                                <a:DisplayName>原始体积</a:DisplayName>
                                <a:DataType>7</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>edo_volume_percent</a:FieldName>
                                <a:AliasName>edoVolumePercent</a:AliasName>
                                <a:DisplayName>图元对应的百分比</a:DisplayName>
                                <a:DataType>7</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>version</a:FieldName>
                                <a:DisplayName>版本号</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>file</a:Name>
                        <a:DisplayName>文件表</a:DisplayName>
                        <a:Catalog>文件</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:ApplyUpdateEnabled>False</a:ApplyUpdateEnabled>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>table_name</a:FieldName>
                                <a:AliasName>tableName</a:AliasName>
                                <a:DisplayName>表名</a:DisplayName>
                                <a:Remark>标识该文件属于哪个表，PC端做部分文件下载时使用</a:Remark>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_id</a:FieldName>
                                <a:AliasName>fileId</a:AliasName>
                                <a:DisplayName>云端文件ID</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_url</a:FieldName>
                                <a:AliasName>fileUrl</a:AliasName>
                                <a:DisplayName>云端路径</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_path</a:FieldName>
                                <a:AliasName>filePath</a:AliasName>
                                <a:DisplayName>本地文件路径</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_hash</a:FieldName>
                                <a:AliasName>fileHash</a:AliasName>
                                <a:DisplayName>文件Hash</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>file_name</a:FieldName>
                                <a:AliasName>fileName</a:AliasName>
                                <a:DisplayName>文件名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>original_file_name</a:FieldName>
                                <a:AliasName>originalFileName</a:AliasName>
                                <a:DisplayName>文件原始名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>business_type</a:FieldName>
                                <a:AliasName>businessType</a:AliasName>
                                <a:DisplayName>所属业务类型</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>specialty</a:Name>
                        <a:DisplayName>专业字典</a:DisplayName>
                        <a:Catalog>元数据</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>elevation_system</a:FieldName>
                                <a:AliasName>elevationSystem</a:AliasName>
                                <a:DisplayName>标高体系</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:EnumNames>1=建筑标高|2=结构标高</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>default_segment_line_color</a:FieldName>
                                <a:AliasName>defaultSegmentLineColor</a:AliasName>
                                <a:DisplayName>流水段颜色</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>default_segment_line_width</a:FieldName>
                                <a:AliasName>defaultSegmentLineWidth</a:AliasName>
                                <a:DisplayName>流水段线宽</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
                <o:Table TableKind="0">
                    <o:TableSchema>
                        <a:Name>element_type</a:Name>
                        <a:DisplayName>构件类型</a:DisplayName>
                        <a:Catalog>元数据</a:Catalog>
                        <a:ExtData>MYSQL,GSP</a:ExtData>
                        <a:CommandEnable>True</a:CommandEnable>
                        <a:PrimaryKeyMinVal>1</a:PrimaryKeyMinVal>
                        <c:FieldSchemas>
                            <o:FieldSchema FieldKind="0">
                                <a:FieldName>id</a:FieldName>
                                <a:DisplayName>主键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>project_id</a:FieldName>
                                <a:AliasName>projectId</a:AliasName>
                                <a:DisplayName>项目id</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>13</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>parent_id</a:FieldName>
                                <a:AliasName>parentId</a:AliasName>
                                <a:DisplayName>本表外键</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>element_type</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="1">
                                <a:FieldName>specialty_id</a:FieldName>
                                <a:AliasName>specialtyId</a:AliasName>
                                <a:DisplayName>专业</a:DisplayName>
                                <c:ExtPropDefs>
                                    <o:ExtPropDef>
                                        <a:Code>DataType</a:Code>
                                        <a:Value>Int64</a:Value>
                                    </o:ExtPropDef>
                                </c:ExtPropDefs>
                                <a:DataType>2</a:DataType>
                                <a:LookupKind>1</a:LookupKind>
                                <a:LookupTableName>specialty</a:LookupTableName>
                                <a:LookupResult>id</a:LookupResult>
                                <a:LookupDescription>name</a:LookupDescription>
                                <a:Aggregate>True</a:Aggregate>
                                <a:MasterTableName>specialty</a:MasterTableName>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>element_type_id</a:FieldName>
                                <a:AliasName>elementTypeId</a:AliasName>
                                <a:DisplayName>构件类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>code</a:FieldName>
                                <a:DisplayName>编码</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>name</a:FieldName>
                                <a:DisplayName>名称</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_used</a:FieldName>
                                <a:AliasName>isUsed</a:AliasName>
                                <a:DisplayName>模型使用标志</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>True</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_show</a:FieldName>
                                <a:AliasName>isShow</a:AliasName>
                                <a:DisplayName>非建模使用标志</a:DisplayName>
                                <a:DataType>1</a:DataType>
                                <a:DefaultExpr>False</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>polygon_offset_factor</a:FieldName>
                                <a:AliasName>polygonOffsetFactor</a:AliasName>
                                <a:DisplayName>多边形偏移系数</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:DefaultExpr>0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>polygon_offset</a:FieldName>
                                <a:AliasName>polygonOffset</a:AliasName>
                                <a:DisplayName>多边形偏移量</a:DisplayName>
                                <a:DataType>4</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>priority</a:FieldName>
                                <a:DisplayName>优先级</a:DisplayName>
                                <a:DataType>6</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="3">
                                <a:FieldName>node_type</a:FieldName>
                                <a:AliasName>nodeType</a:AliasName>
                                <a:DisplayName>节点类型</a:DisplayName>
                                <a:DataType>2</a:DataType>
                                <a:EnumNames>1=分组|2=构件类型</a:EnumNames>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>is_allow_split</a:FieldName>
                                <a:AliasName>isAllowSplit</a:AliasName>
                                <a:DisplayName>允许切割</a:DisplayName>
                                <a:DataType>1</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>remark</a:FieldName>
                                <a:DisplayName>备注</a:DisplayName>
                                <a:DataType>10</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>wireframe_line_width</a:FieldName>
                                <a:AliasName>wireframeLineWidth</a:AliasName>
                                <a:DisplayName>线宽</a:DisplayName>
                                <a:DataType>7</a:DataType>
                                <a:DefaultExpr>1.0</a:DefaultExpr>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_revision</a:FieldName>
                                <a:AliasName>sysRevision</a:AliasName>
                                <a:DisplayName>系统-乐观锁版本号</a:DisplayName>
                                <a:DataType>13</a:DataType>
                                <a:IsIndexField>True</a:IsIndexField>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_create_time</a:FieldName>
                                <a:AliasName>sysCreateTime</a:AliasName>
                                <a:DisplayName>系统-记录创建时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modified_time</a:FieldName>
                                <a:AliasName>sysModifiedTime</a:AliasName>
                                <a:DisplayName>系统-记录修改时间</a:DisplayName>
                                <a:DataType>9</a:DataType>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_creator_id</a:FieldName>
                                <a:AliasName>sysCreatorId</a:AliasName>
                                <a:DisplayName>系统-创建人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                            <o:FieldSchema FieldKind="2">
                                <a:FieldName>sys_modifier_id</a:FieldName>
                                <a:AliasName>sysModifierId</a:AliasName>
                                <a:DisplayName>系统-最后修改人</a:DisplayName>
                                <a:StrLength>255</a:StrLength>
                            </o:FieldSchema>
                        </c:FieldSchemas>
                    </o:TableSchema>
                    <o:TableData/>
                </o:Table>
            </c:Tables>
        </o:Database>
    </c:Databases>
</GSPModel>
