import requests

url = "https://discovery-api.intern-ai.org.cn/v1/chat/completions"
headers = {
    "Authorization": "Bearer sk-3bf26300294802b3cff79ea6b3b485a3899c227756a7e2b2ea50ef2a065f24a7",
    "Content-Type": "application/json"
}
data = {
    "model": "deepseek-v4-pro-0813",
    "messages": [{"role": "user", "content": "hi"}]
}

try:
    response = requests.post(url, headers=headers, json=data, timeout=10)
    print("状态码:", response.status_code)
    print("返回内容:", response.text)
except Exception as e:
    print("请求彻底挂了:", e)