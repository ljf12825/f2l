import urllib.request
import json

# 拉取题目
print("正在拉取题库...")
url = "https://codeforces.com/api/problemset.problems"
response = urllib.request.urlopen(url)
data = json.loads(response.read().decode('utf-8'))

problems = data['result']['problems']
stats = data['result']['problemStatistics']

# 建立快速查找字典
problem_dict = {}
for i, p in enumerate(problems):
    key = f"{p['contestId']}{p['index']}"
    problem_dict[key] = {
        'name': p['name'],
        'rating': p.get('rating', 0),
        'tags': p['tags'],
        'solved': stats[i]['solvedCount']
    }

# 保存成JSON文件
with open('problems.json', 'w') as f:
    json.dump(problem_dict, f)

print(f"完成！共 {len(problem_dict)} 道题")

# 测试查询
while True:
    pid = input("\n输入题号 (如 4A，输入 q 退出): ").strip()
    if pid.lower() == 'q':
        break
    
    if pid in problem_dict:
        p = problem_dict[pid]
        print(f"题目: {p['name']}")
        print(f"难度: {p['rating']}")
        print(f"标签: {', '.join(p['tags'])}")
        print(f"通过数: {p['solved']}")
    else:
        print("未找到该题目")

# 按标签筛选
print("\n=== DP标签前5题 ===")
count = 0
for key, p in problem_dict.items():
    if 'dp' in p['tags']:
        print(f"{key}: {p['name']} (难度:{p['rating']})")
        count += 1
        if count >= 5:
            break

# 按难度筛选
print("\n=== 800分题目（新手友好）===")
count = 0
for key, p in problem_dict.items():
    if p['rating'] == 800:
        print(f"{key}: {p['name']}")
        count += 1
        if count >= 5:
            break
