/*********************************************************************************************************************************
  MySQL_Generic.h
      
  Library for communicating with a MySQL or MariaDB Server
  
  Based on and modified from Dr. Charles A. Bell's MySQL_Connector_Arduino Library https://github.com/ChuckBell/MySQL_Connector_Arduino
  to support nRF52, SAMD21/SAMD51, SAM DUE, STM32F/L/H/G/WB/MP1, ESP8266, ESP32, WT32_ETH01, Teensy, Portenta_H7, etc. boards 
  using W5x00, ENC28J60, LAM8742A Ethernet, WiFiNINA, ESP-AT, built-in ESP8266/ESP32 WiFi, Portenta Ethernet/WiFi

  The library provides simple and easy Client interface to MySQL or MariaDB Server.
  
  Built by Khoi Hoang https://github.com/khoih-prog/MySQL_MariaDB_Generic
  Licensed under MIT license
  
  Version: 1.7.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      13/08/2020 Initial coding/porting to support nRF52, SAM DUE and SAMD21/SAMD51 boards using W5x00 Ethernet
                                  (Ethernet, EthernetLarge, Ethernet2, Ethernet3 library), WiFiNINA and ESP8266/ESP32-AT shields
  ...
  1.4.0   K Hoang      05/09/2021 Add support to Teensy 4.1 using QNEthernet
  1.5.0   K Hoang      17/09/2021 Add support to Portenta_H7, using either WiFi or Vision-shield Ethernet
  1.5.1   K Hoang      10/10/2021 Update `platform.ini` and `library.json`
  1.5.2   K Hoang      01/12/2021 Auto detect ESP32 core for LittleFS. Fix bug in examples for WT32_ETH01
  1.6.0   K Hoang      10/03/2022 Fix memory leak bug. Optimize code
  1.6.1   K Hoang      12/03/2022 Fix memory management bug
  1.7.0   K Hoang      12/03/2022 Convert to `h-only` style library
 **********************************************************************************************************************************/

#ifndef MYSQL_GENERIC_H
#define MYSQL_GENERIC_H

#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_ENC || USE_ETHERNET_ESP8266 || \
      USE_UIP_ETHERNET || USE_NATIVE_ETHERNET || USE_QN_ETHERNET || USE_CUSTOM_ETHERNET || USE_ETHERNET_PORTENTA_H7 )

  #include "MySQL_Generic_Ethernet.h"
  
#elif ( USING_WIFININA_GENERIC || USING_WIFININA ) 

  #include "MySQL_Generic_WiFiNINA.h" 

#elif ( ESP8266 || ESP32 || USING_WIFI_ESP8266_AT || USING_WIFININA_GENERIC || USING_WIFININA || USING_WIFIESPAT_LIB || \
        USING_WIFI_CUSTOM || USE_WIFI_PORTENTA_H7 )

  #include "MySQL_Generic_WiFi.h"


#else

  #error Must select a Ethernet / WiFi module and Library
  
#endif

#include <MySQL_Generic.hpp>

#include <MySQL_Generic_Connection_Impl.h>
#include <MySQL_Generic_Query_Impl.h>
#include <MySQL_Generic_Encrypt_Sha1_Impl.h>
#include <MySQL_Generic_Packet_Impl.h>
 
#endif    //MYSQL_GENERIC_H