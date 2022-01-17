# coding=gbk
import time
from appium import webdriver
from appium.webdriver.common.touch_action import TouchAction
desired_caps = {}
desired_caps['platformName'] = 'Android'
desired_caps['automationName'] = 'UIAutomator2'
desired_caps['autoGrantPermissions'] = True
desired_caps['unicodeKeyboard'] = True
desired_caps['resetKeyboard'] = True
desired_caps['appPackage'] = 'com.dnielfe.manager'
desired_caps['appActivity'] = 'com.dnielfe.manager.BrowserActivity'
desired_caps['app'] = 'C:\\南\\大三上\\软件工程\\实验\\实验5\\实验5_191220008_陈南曈_SimpleExplorer\\SimpleExplorer_new.apk'
desired_caps['platformVersion'] = '11'
driver = webdriver.Remote('http://127.0.0.1:4723/wd/hub', desired_caps)

time.sleep(3)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
TouchAction(driver).long_press(el).perform()

time.sleep(1)

el = driver.find_element_by_accessibility_id("Search")
el.click()

time.sleep(1)

el = driver.find_elements_by_class_name("android.widget.LinearLayout")[4]
el.click()

time.sleep(1)

el = driver.find_element_by_id("android:id/button1")
el.click()

time.sleep(1)

el = driver.find_element_by_accessibility_id("Folder information")
el.click()

time.sleep(1)

el = driver.find_element_by_id("android:id/button3")
el.click()

time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[0]
TouchAction(driver).long_press(el).perform()

time.sleep(1)

el = driver.find_element_by_accessibility_id("Move")
el.click()

time.sleep(1)

el = driver.find_elements_by_id("com.dnielfe.manager:id/row_image")[1]
TouchAction(driver).long_press(el).perform()

time.sleep(1)

el = driver.find_element_by_accessibility_id("Folder information")
el.click()

time.sleep(1)

driver.quit()
