import pyautogui
import time

# ===== SETTINGS =====
WHATSAPP_ICON = (1233, 1061)   # change this!
SEARCH_BAR = (310, 156)       # change this!

CONTACT_NAME = "Jayant"
MESSAGE = "Hello bro, automated message 😎"

# ===== START =====
time.sleep(3)  # time to prepare

# 1. Click WhatsApp on taskbar
pyautogui.click(WHATSAPP_ICON)
time.sleep(5)  # wait for app to open

# 2. Click search bar
pyautogui.click(SEARCH_BAR)
time.sleep(1)

# 3. Type contact name
pyautogui.write(CONTACT_NAME, interval=0.05)
time.sleep(2)

# 4. Open chat
pyautogui.press("enter")
time.sleep(1)

# 5. Type message
pyautogui.write(MESSAGE, interval=0.05)

# 6. Send message
pyautogui.press("enter")