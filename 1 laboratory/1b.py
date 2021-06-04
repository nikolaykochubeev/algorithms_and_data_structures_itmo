a, b = map(int, open('aplusbb.in').readline().split())
aplusbb_out = open('aplusbb.out', 'w')
print(a + b * b, file=aplusbb_out)
aplusbb_out.close()
