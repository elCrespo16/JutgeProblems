import requests
import re
import os
import time
from bs4 import BeautifulSoup

url = "https://jutge.org/"
data = {
    "action":"/",
    "email":"CAMBIAR",
    "password":"CAMBIAR",
    "submit":""
}
path = "./programas/"
if not os.path.exists(path):
    os.makedir(path)
arxivs = set(os.listdir(path))
numProblems = 0
numDownload = 0
failedList = []
with requests.session() as req:
    r = req.post(url, data)
    r = req.get(f"{url}problems/accepted")
    soup = BeautifulSoup(r.text, "html.parser")
    problems = soup.find_all("a")
    for problem in problems:
        if problem.parent.name == "td" and f"{problem.string}.cc" not in arxivs:
            arxivs.add(problem.string)
            print(problem.string)
            urlAux = f"{url[0 : len(url) - 1]}{problem["href"]}/submissions"
            soup2 = BeautifulSoup(req.get(urlAux).text, "html.parser")
            submissions = soup2.find_all("tr")
            for submission in submissions:
                greenLight = False
                for element in submission.children:
                    if hasattr(element, "children"):
                        for tag in element.children:
                            tagString = str(tag.string)
                            if tag.name == "img" and re.search("green", tag["src"]):
                                greenLight = True
                            if greenLight and re.match("S[0-9]{3}", tagString):
                                urlAux = url[0 : len(url) - 1] + tag["href"]
                                numProblems = numProblems + 1
                                r = req.get(urlAux, timeout=20)
                                urlAux = f"{urlAux}/download"
                                r = req.get(urlAux, timeout=20)
                                if r.text:
                                    print("Conseguido")
                                    numDownload = numDownload + 1
                                    with open(f"{path}{problem.string}.cc", "w+") as problemSol:
                                        problemSol.write(r.text)
                                else:
                                    print("Failed")
                                    failedList.append(problem.string)
                if greenLight:
                    break
print(f"Numero de problemas acceptados {numProblems}")
print(f"Numero de problemas descargados {numDownload}")
print("Lista de fallos:")
for e in failedList:
    print(e)
