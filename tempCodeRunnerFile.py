import base64
import json
import urllib.request

url = "https://workwithus.staging.scalerailabs.com/g/gdPnTXlKCRcF1t1H6Oz1"
bearer_token = "eyJjbGVhcmVkIjozLCJleHAiOjE3ODg1OTY0MTIsImlhdCI6MTc4ODQyNTIyMywicmVmIjoiODFkM2U3NGQ3OTRhMDkxNyJ9.RSRlX1cT4qhEVJnOOieiew"

headers = {
    "Authorization": f"Bearer {bearer_token}",
    "Content-Type": "application/json",
}

# 1. Fetch fresh questions and token
req = urllib.request.Request(url, headers={"Authorization": f"Bearer {bearer_token}"})
with urllib.request.urlopen(req) as response:
    data = json.loads(response.read().decode())

game_token = data["token"]

# 2. Extract and decode the JWT payload to get embedded answers
payload_b64 = game_token.split(".")[0]
# Fix base64 padding
payload_b64 += "=" * (-len(payload_b64) % 4)
decoded_json = json.loads(base64.b64decode(payload_b64).decode("utf-8"))

answers = decoded_json["a"]

# 3. Submit the token and answers immediately
payload = json.dumps({"token": game_token, "answers": answers}).encode("utf-8")

post_req = urllib.request.Request(url, data=payload, headers=headers, method="POST")
with urllib.request.urlopen(post_req) as response:
    result = json.loads(response.read().decode())

print(json.dumps(result, indent=2))