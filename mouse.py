import pyautogui
import time

time.sleep(3)  # gives you time to switch window

while True:
    x, y = pyautogui.position()
    print(f"X: {x} Y: {y}", end="\r")

310 156