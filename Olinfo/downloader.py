import requests, json, codecs, os
s = requests.Session()
site = "https://training.olinfo.it/api/user"
utente = input("INSERISCI LO USERNAME: ")
password = input("INSERISCI LA PASSWORD: ")
s.post(site, json={"action":"login", "keep_signed":True, "password":password, "username":utente})
jsonResp = s.post(site, json={"action":"get", "username":"Alan_Bovo"}).text
for i in json.loads(jsonResp)["scores"]:
    siteTask = "https://training.olinfo.it/api/submission"
    jsonRespTask = s.post(siteTask, json={"task_name":i["name"], "action":"list"}).text
    max = -1
    dig = ""
    name = ""
    for e in json.loads(jsonRespTask)["submissions"]:
        if int(e["score"]) > max:
            max = e["score"]
            dig = e["files"][0]["digest"]
            name = e["files"][0]["name"]
    text = s.get(f"https://training.olinfo.it/api/files/{dig}/{name}").text.encode().replace(b"\n\n", b"\n")
    fileRead = open(os.getcwd() + "\\training\\" + name, "r")
    f = str(fileRead.readline())
    if int(f[f.find(":")+2:f.find(".")]) < max:
        with open(os.getcwd() + "\\training\\" + name, "wb") as file:
            file.write(f"// Punti: {max}\n".encode() + text)
        print("Fatto: " + name)
    else:
        print("Non fatto: " + name)
    