import numpy.random as rnd

def bissextile(year):
    return year%4 == 0 and (year%100 > 1 or year%400 == 0)

nb_jour = {"1" : 31, "2" : 2}

year = 1600 + rnd.randint(0, 422)
nb_jour = {"1" : 31, "2" : 28, "3" : 31, "4" : 30, "5" : 31, "6" : 30, "7" : 31, "8" : 31, "9" : 30, "10" : 31, "11" : 30, "12" : 31,}
if bissextile(year):
    nb_jour["2"] += 1
mois = rnd.randint(1, 13)
jour = rnd.randint(1, nb_jour[str(mois)] + 1)

f = open("date.txt", 'w')
f.write(f"{year}-{mois:02}-{jour:02}")
f.close()

f = open("nb_daydle.txt", 'r')
try:
    nb_daydle = int(f.readlines()[0]) + 1
except:
    print(f.readlines()[0])
    nb_daydle = 1
f.close()

f = open("nb_daydle.txt", "w")
f.write(f"{nb_daydle}")
f.close()
