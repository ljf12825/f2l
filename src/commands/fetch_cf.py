import urllib.request
import json

print("fetching...")
url = "https://codeforces.com/api/problemset.problems"
response = urllib.request.urlopen(url)
data = json.loads(response.read().decode('utf-8'))

problems = data['result']['problems']
stats = data['result']['problemStatistics']

problem_dict = {}
for i, p in enumerate(problems):
    key = f"{p['contestId']}{p['index']}"
    problem_dict[key] = {
        'name': p['name'],
        'rating': p.get('rating', 0),
        'tags': p['tags'],
        'solved': stats[i]['solvedCount']
    }

with open('problems.json', 'w') as f:
    json.dump(problem_dict, f)

print(f"finish! {len(problem_dict)} results in total")
