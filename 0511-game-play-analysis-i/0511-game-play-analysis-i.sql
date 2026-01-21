# Write your MySQL query statement below
SELECT Player_id, MIN(event_date) as first_login FROM Activity
GROUP BY Player_id;