;; I like this approach because it shows the simplicity of clojure

(def fib (lazy-cat [0 1] (map + fib (rest fib))))