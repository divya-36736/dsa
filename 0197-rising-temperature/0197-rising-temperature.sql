# Write your MySQL query statement below
#W1 current and w2 is perivous
SELECT w1.id FROM Weather w1
INNER JOIN Weather w2
ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
AND w1.temperature > w2.temperature;
