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

# test case1: search existent file
el = driver.find_element_by_id("com.dnielfe.manager:id/search")
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search_button")
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search_src_text")
el.send_keys('Alarms')
driver.press_keycode(66)
time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
el.click()
time.sleep(1)

driver.back()
time.sleep(1)

# test case2: search inexistent file
el = driver.find_element_by_id("com.dnielfe.manager:id/search")
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search_button")
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search_src_text")
el.send_keys('hhh')
driver.press_keycode(66)
time.sleep(1)


driver.quit()
