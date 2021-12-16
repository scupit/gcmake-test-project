import json

fin = open("./random_json.json", mode="r")
fout = open("./copied_random_json.json", mode="w")

loaded_json = json.load(fin)
json.dump(loaded_json, fout)

fin.close()
fout.close()