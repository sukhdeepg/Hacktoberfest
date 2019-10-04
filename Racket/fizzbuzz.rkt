;; I'm learning Racket, so here's a Racket implementation of FizzBuzz!

;; (fizzbuzz n) produces Fizz, Buzz, FizzBuzz or n
;; depending on the value of n.
;; fizzbuzz: Num -> (anyof Str Num)
;; Examples:
(check-expect (fizzbuzz 3) "Fizz")
(check-expect (fizzbuzz 5) "Buzz")
(check-expect (fizzbuzz 15) "FizzBuzz")

(define (fizzbuzz n)
  (cond
       [(and
         (= (modulo n 3) 0)
         (= (modulo n 5) 0))
        "FizzBuzz"]
       [(= (modulo n 3) 0) "Fizz"]
       [(= (modulo n 5) 0) "Buzz"]
       [else n]))

;; Tests
(check-expect (fizzbuzz 11) 11)
(check-expect (fizzbuzz 25) "Buzz")
(check-expect (fizzbuzz 30) "FizzBuzz")
