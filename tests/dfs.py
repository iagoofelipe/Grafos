def dfs(grafos, inicio):
    visitados = set()
    pilha = [inicio]
    visitados.add(inicio)

    while pilha:
        u = pilha.pop()
        print(u)
        for v in grafos[u]:
            if v not in visitados:
                visitados.add(v)
                pilha.append(v)

# Exemplo de uso
grafos = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

inicio = 'A'
dfs(grafos, inicio)