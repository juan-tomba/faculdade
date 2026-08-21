intervalos = [[1, 4], [2,3] , [4,6], [8,9]]

intervalos.sort(key=lambda x: x[1])

counter = 0
ultimo_final = -1
for i in intervalos:
    if i[0] > ultimo_final:
        counter += 1
        ultimo_final = i[1]

print(counter)