@echo off

wsdl2h -o mds.h http://10.158.249.196:7001/InterfaceWS/InterfaceBusiness/services/DetectService?wsdl

soapcpp2 -i -C -x mds.h -I c:\gsoap\gsoap-2.8\gsoap\import 

pause
