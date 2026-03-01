nums = [5, 6, -9, 2, 4, -2, -5, 2]
result = sum $ map (^2) $ filter (>0) nums