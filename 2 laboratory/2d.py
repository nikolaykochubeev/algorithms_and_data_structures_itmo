in_antiqs = int(open("antiqs.in").read())
out_antiqs = open("antiqs.out", "w")
out_array = []
for i in range(1, in_antiqs+1):
    out_array.append(i)

for i in range(in_antiqs):
    c = out_array[i]
    out_array[i] = out_array[i//2]
    out_array[i//2] = c
print(' '.join([str(item) for item in out_array]), file=out_antiqs)
out_antiqs.close()

