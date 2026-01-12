import heapq

def main():
    def is_move_valid(row, col, previous_height):
        if not (0 <= row < rows_count and 0 <= col < cols_count):
            return False
        current_height = height_map[row][col]
        return abs(current_height - previous_height) <= 100

    def find_shortest_path(from_row, from_col, to_row, to_col):
        pq = [(0, from_row, from_col)]

        min_distances = [[float('inf')] * cols_count for _ in range(rows_count)]
        min_distances[from_row][from_col] = 0

        while pq:
            dist, r, c = heapq.heappop(pq)

            if r == to_row and c == to_col:
                return dist

            if dist > min_distances[r][c]:
                continue

            current_h = height_map[r][c]
            
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                
                if is_move_valid(nr, nc, current_h):
                    new_dist = dist + 1
                    if new_dist < min_distances[nr][nc]:
                        min_distances[nr][nc] = new_dist
                        heapq.heappush(pq, (new_dist, nr, nc))
        
        return float('inf')

    line = input().split()
    rows_count, cols_count = map(int, line)

    height_map = []
    for _ in range(rows_count):
        row_heights = list(map(int, input().split()))
        height_map.append(row_heights)

    start_row, start_col = map(int, input().split())
    cargo_row, cargo_col = map(int, input().split())
    finish_row, finish_col = map(int, input().split())

    path1 = find_shortest_path(start_row, start_col, cargo_row, cargo_col)
    path2 = find_shortest_path(cargo_row, cargo_col, finish_row, finish_col)

    print(path1 + path2)

if __name__ == "__main__":
    main()