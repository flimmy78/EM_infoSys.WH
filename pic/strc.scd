<?xml version="1.0" encoding="UTF-8"?>
<!-- 编辑使用 XMLSpy v2006 U (http://www.altova.com) 由 any (any) -->
<!-- 编辑使用 XMLSpy v2006 U (http://www.altova.com) 由 any (any) -->
<SCL xmlns="http://www.iec.ch/61850/2003/SCL" xmlns:ext="http://nari-relays.com" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.iec.ch/61850/2003/SCL SCL.xsd">
    <Header id="PCS9XX" nameStructure="IEDName" toolID="NsConfig">
        <History>
            <Hitem revision="0.9" version="1.0" when="2010/09/30 09:37:46" why="update the file"/>
        </History>
    </Header>
    <Communication>
        <SubNetwork desc="" name="GOOSE-A" type="">
            <ConnectedAP apName="G1" iedName="CL2201">
                <GSE cbName="gocb0" ldInst="PI">
                    <Address>
                        <P type="MAC-Address">01-0C-CD-01-00-04</P>
                        <P type="VLAN-ID">000</P>
                        <P type="VLAN-PRIORITY">1</P>
                        <P type="APPID">1004</P>
                    </Address>
                    <MinTime multiplier="m" unit="s">2</MinTime>
                    <MaxTime multiplier="m" unit="s">5000</MaxTime>
                </GSE>
            </ConnectedAP>
        </SubNetwork>
    </Communication>
    <IED configVersion="V1.0" desc="220kV线路1测控" manufacturer="SNR" name="CL2201" type="">
        <Services>
            <DynAssociation/>
            <GetDirectory/>
            <GetDataObjectDefinition/>
            <DataObjectDirectory/>
            <GetDataSetValue/>
            <ReadWrite/>
            <ConfReportControl max="18"/>
            <GetCBValues/>
            <ReportSettings bufTime="Dyn" cbName="Conf" datSet="Conf" intgPd="Dyn" optFields="Conf" rptID="Conf" trgOps="Dyn"/>
            <ConfLNs fixLnInst="true" fixPrefix="true"/>
        </Services>
        <AccessPoint clock="false" desc="常规mms服务功能" name="S1" router="false">
            <Server>
                <Authentication none="true"/>
                <LDevice desc="信号与控制" inst="CTRL">
                    <LN0 inst="" lnClass="LLN0" lnType="SZNR_LLN0_0">
                        <DataSet desc="五防联锁" name="dsGOOSE">
                            <FCDA doName="DPYX01" fc="ST" ldInst="CTRL" lnClass="GGIO" lnInst="4"/>
                            <FCDA doName="DPYX02" fc="ST" ldInst="CTRL" lnClass="GGIO" lnInst="4"/>
                        </DataSet>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsDin1" intgPd="0" name="brcbDin1" rptID="brcbDin1">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsDin2" intgPd="0" name="brcbDin2" rptID="brcbDin2">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsDin3" intgPd="0" name="brcbDin3" rptID="brcbDin3">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsDin4" intgPd="0" name="brcbDin4" rptID="brcbDin4">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsSKOut" intgPd="0" name="brcbSK" rptID="brcbSK">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsSBT" intgPd="0" name="brcbSBT" rptID="brcbSBT">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsSKOperStat" intgPd="0" name="brcbSKStat" rptID="brcbSKStat">
                            <TrgOps dchg="true" period="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <ReportControl bufTime="0" buffered="true" confRev="1" datSet="dsCommState1" intgPd="0" name="brcbCommState1" rptID="brcbCommState1">
                            <TrgOps dchg="true"/>
                            <OptFields configRef="true" dataRef="true" dataSet="true" entryID="true" reasonCode="true" seqNum="true" timeStamp="true"/>
                            <RptEnabled max="18"/>
                        </ReportControl>
                        <GSEControl appID="CL2201CTRL/LLN0$GO$sttgocb0" confRev="1" datSet="dsGOOSE" name="sttgocb0" type="GOOSE">
                            <Private type="GooseCfg"/>
                        </GSEControl>
                    </LN0>
                    <LN desc="双点遥信" inst="4" lnClass="GGIO" lnType="SZNR_GGIO_TYX_PRS7K">
                        <DOI desc="双点遥信01" name="DPYX01">
                            <DAI name="dU">
                                <Val>双点遥信01</Val>
                            </DAI>
                            <DAI name="stVal" sAddr="RDYXKR_368_Y"/>
                            <DAI name="ctlModel" sAddr="RWYKDP_0/368_N"/>
                            <SDI name="Cancel">
                                <DAI name="ctlVal" sAddr="RWYKDP_0/368_N"/>
                            </SDI>
                            <SDI name="Oper">
                                <DAI name="ctlVal" sAddr="RWYKDP_0/368_N"/>
                            </SDI>
                            <SDI name="SBOw">
                                <DAI name="ctlVal" sAddr="RWYKDP_0/368_N"/>
                            </SDI>
                        </DOI>
                        <DOI desc="双点遥信02" name="DPYX02">
                            <DAI name="dU">
                                <Val>双点遥信02</Val>
                            </DAI>
                            <DAI name="stVal" sAddr="RDYXKR_369_Y"/>
                            <DAI name="ctlModel" sAddr="RWYKDP_1/369_N"/>
                            <SDI name="Cancel">
                                <DAI name="ctlVal" sAddr="RWYKDP_1/369_N"/>
                            </SDI>
                            <SDI name="Oper">
                                <DAI name="ctlVal" sAddr="RWYKDP_1/369_N"/>
                            </SDI>
                            <SDI name="SBOw">
                                <DAI name="ctlVal" sAddr="RWYKDP_1/369_N"/>
                            </SDI>
                        </DOI>
                        <DOI desc="双点遥信03" name="DPYX03">
                            <DAI name="dU">
                                <Val>双点遥信03</Val>
                            </DAI>
                            <DAI name="stVal" sAddr="RDYXKR_370_Y"/>
                            <DAI name="ctlModel" sAddr="RWYKDP_2/370_N"/>
                            <SDI name="Cancel">
                                <DAI name="ctlVal" sAddr="RWYKDP_2/370_N"/>
                            </SDI>
                            <SDI name="Oper">
                                <DAI name="ctlVal" sAddr="RWYKDP_2/370_N"/>
                            </SDI>
                            <SDI name="SBOw">
                                <DAI name="ctlVal" sAddr="RWYKDP_2/370_N"/>
                            </SDI>
                        </DOI>
                    </LN>
                </LDevice>
            </Server>
        </AccessPoint>
    </IED>
    <DataTypeTemplates>
        <LNodeType desc="双点遥信" id="SZNR_GGIO_TYX_PRS7K" lnClass="GGIO">
            <DO desc="双点遥信01" name="DPYX01" type="CN_DPC_CL2201"/>
            <DO desc="双点遥信02" name="DPYX02" type="CN_DPC_CL2201"/>
        </LNodeType>
        <DOType cdc="DPC" id="CN_DPC_CL2201">
            <DA bType="Struct" fc="CO" name="SBOw" type="CN_SBOw_Oper_SDPC_CL2201"/>
            <DA bType="Struct" fc="CO" name="Oper" type="CN_SBOw_Oper_SDPC_CL2201"/>
            <DA bType="Struct" fc="CO" name="Cancel" type="CN_Cancel_SDPC_CL2201"/>
            <DA bType="Dbpos" dchg="true" fc="ST" name="stVal"/>
            <DA bType="Quality" fc="ST" name="q" qchg="true"/>
            <DA bType="Timestamp" fc="ST" name="t"/>
            <DA bType="BOOLEAN" fc="SV" name="subEna"/>
            <DA bType="Dbpos" fc="SV" name="subVal"/>
            <DA bType="Quality" fc="SV" name="subQ"/>
            <DA bType="VisString64" fc="SV" name="subID"/>
            <DA bType="Struct" fc="CF" name="pulseConfig" type="CN_PulseConfig_CL2201"/>
            <DA bType="Enum" fc="CF" name="ctlModel" type="ctlModel_CL2201"/>
            <DA bType="INT32U" fc="CF" name="sboTimeout"/>
            <DA bType="Enum" fc="CF" name="sboClass" type="sboClass_CL2201"/>
            <DA bType="Unicode255" fc="DC" name="dU"/>
        </DOType>
        <EnumType id="sboClass_PM2201B">
            <EnumVal ord="0">operate-once</EnumVal>
            <EnumVal ord="1">operate-many</EnumVal>
        </EnumType>
    </DataTypeTemplates>
</SCL>
