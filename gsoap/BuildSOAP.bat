@echo off

wsdl2h -o mds.h http://10.229.255.177:8080/InterfaceWS/InterfaceBusiness/services/DetectService?wsdl

soapcpp2 -i -C -x mds.h -I c:\gsoap\gsoap-2.8\gsoap\import 

pause
