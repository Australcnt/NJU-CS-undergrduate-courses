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

# test case1: compress file(s)/folder(s) which do not exist
el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
TouchAction(driver).long_press(el).perform()
time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[1]
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search")
el.click()
time.sleep(1)

el = driver.find_elements_by_class_name("android.widget.LinearLayout")[2]
el.click()
time.sleep(1)

el = driver.find_element_by_id("android:id/button1")
el.click()
time.sleep(1)

# test case2: compress file(s)/folder(s) which already exist
el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
TouchAction(driver).long_press(el).perform()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search")
el.click()
time.sleep(1)

el = driver.find_elements_by_class_name("android.widget.LinearLayout")[3]
el.click()
time.sleep(1)

el = driver.find_element_by_id("android:id/button1")
el.click()
time.sleep(1)

# test case3: compress file(s)/folder(s) to inexistent path
el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
TouchAction(driver).long_press(el).perform()
time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[1]
el.click()
time.sleep(1)

el = driver.find_element_by_id("com.dnielfe.manager:id/search")
el.click()
time.sleep(1)

el = driver.find_elements_by_class_name("android.widget.LinearLayout")[2]
el.click()
time.sleep(1)

el = driver.find_element_by_class_name("android.widget.EditText")
el.clear()
time.sleep(1)

el = driver.find_element_by_class_name("android.widget.EditText")
el.send_keys('storage/emulated/0/aaa/zipfile.zip')
time.sleep(1)

el = driver.find_element_by_id("android:id/button1")
el.click()
time.sleep(1)


driver.quit()
