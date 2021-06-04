a, b = map(int, open('aplusb.in').readline().split())
aplusb_out = open('aplusb.out', 'w')
print(a + b, file=aplusb_out)
aplusb_out.close()
