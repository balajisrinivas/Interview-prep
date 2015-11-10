def init_visited(visited, rows, cols):
    for i in range(rows):
        temp_list = []
        for j in range(cols):
            temp_list.append(0)
        visited.append(temp_list)
    print "visited: ", visited

def check_valid_neighbor(matrix, visited, neighbor_row, neighbor_col, rows, cols):
    print "    check valid neighbor called for ", neighbor_row, ", ", neighbor_col
    return neighbor_row >= 0 and neighbor_row < rows and neighbor_col >=0 and neighbor_col < cols and matrix[neighbor_row][neighbor_col] == 1 and visited[neighbor_row][neighbor_col] == 0

def perform_dfs(matrix, visited, row, col, rows, cols):
    print "  dfs caleed for ", row, ", ", col, visited
    neighbor_row_indices = [-1, 0, 0, 1]
    neighbor_col_indices = [0, -1, 1, 0]
    print "visited before", visited
    visited[row][col] = 1
    print "visited after", visited
    for i in range(len(neighbor_row_indices)):
        neighbor_row = row + neighbor_row_indices[i]
        neighbor_col = col + neighbor_col_indices[i]
        if check_valid_neighbor(matrix, visited, neighbor_row, neighbor_col, rows, cols):
            perform_dfs(matrix, visited, neighbor_row, neighbor_col, rows, cols)


    
def count_islands(grid):
    rows = len(grid)
    cols = len(grid[0])
    print "rows:", rows, " cols:", cols
    visited = []
    count = 0
    init_visited(visited, rows, cols)
    print visited
    for i in range(rows):
        for j in range(cols):
            print i, j
            if grid[i][j] == 1 and visited[i][j] == 0:
                print "island starting at ", i, ", ", j
                perform_dfs(grid, visited, i, j, rows, cols)
                count = count + 1
    return count


matrix = [[1, 1, 0, 0, 0],
	[1, 1, 0, 0, 0],
	[0, 0, 1, 0, 0],
	[0, 0, 0, 1, 1]]

matrix1 = [[1, 1, 1, 1, 0],
	[1, 1, 0, 1, 0],
	[1, 1, 0, 0, 0],
	[0, 0, 0, 0, 0]]

matrix2 = [[1, 1, 0, 0, 0],
         [0, 1, 0, 0, 1],
         [1, 0, 0, 1, 1],
         [0, 0, 0, 0, 0],
         [1, 0, 1, 0, 1]]
for i in matrix:
	print i
print count_islands(matrix)

