# -*- coding:utf8 -*-
import time
from appium import webdriver
from appium.webdriver.common.touch_action import TouchAction

desired_caps = {}
desired_caps['platformName'] = 'Android'
desired_caps['platformVersion'] = '11.0.0'
desired_caps['deviceName'] = 'Pixel 2 API 30'
desired_caps['noReset'] = True
desired_caps["unicodeKeyboard"] = True
desired_caps["resetKeyboard"] = True
desired_caps['appActivity'] = 'com.dnielfe.manager.BrowserActivity'
desired_caps['appPackage'] = 'com.dnielfe.manager'

# test case0: set connection to Appium
driver = webdriver.Remote('http://127.0.0.1:4723/wd/hub', desired_caps)
driver.implicitly_wait(20)
time.sleep(3)

# test case1: view settings
el = driver.find_element_by_class_name("android.widget.ImageButton")
el.click()
time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/title")[3]
el.click()
time.sleep(1)


driver.quit()
