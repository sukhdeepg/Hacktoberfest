-- In terminal run the command 'gchi quicksort.hs' and then use 'quicksort [4,3,2,-2,342,-3,4-55,324,-77]' or
-- other example array.

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort l ++ [x] ++ quicksort r
    where
        l  = filter (< x) xs
        r = filter (>= x) xs