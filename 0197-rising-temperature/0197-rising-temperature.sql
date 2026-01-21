# Write your MySQL query statement below
#W1 current and w2 is perivous
#brute force
SELECT id
FROM Weather w
WHERE temperature >
(
    SELECT temperature
    FROM Weather
    WHERE recordDate = DATE_SUB(w.recordDate, INTERVAL 1 DAY)
);
