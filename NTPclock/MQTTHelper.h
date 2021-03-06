//----------------------------------------------------------------------------------------------------------------
// MQTTHelper.h
// 
// Manages controlling all MQTT communication & subscriptions.
// For ease, we define a global object that can be used for all MQTT-related functions
// 
// Author - Joshua Villwock
// Created - 2016-12-09
// License - Mozilla Public License 2.0 (Do what you want, credit the author, must release under same license)
//----------------------------------------------------------------------------------------------------------------

#ifndef __MQTTHelper_H__
#define __MQTTHelper_H__

#include <ESP8266WiFi.h>
#include <PubSubClient.h> // MQTT Messaging Library

//Sadly, it can't be a class member, due to limitations in the library
void MQTTCallbackShim(char* topic, byte* payload, unsigned int length);

class MQTTHelper
{
  WiFiClient espClient;
  PubSubClient mqttClient;
  unsigned long lastMQTTReconnect;
  
public:
  void mqttLoop();
  void connect();
  void reconnect();
  boolean publishMQTT(const char* channel, const char* data, bool retained);
  boolean subscribeTopic(char* topic, int qos);
  void MQTTCallback(char* topic, byte* payload, unsigned int length);
};

extern MQTTHelper MQTT_Helper;

#endif //__MQTTHelper_H__
