# Write your MySQL query statement below
select s1.student_id, s1.student_name, sub.subject_name, count(e.student_id) as attended_exams
from Students s1
cross join subjects sub
left join Examinations e
on s1.student_id = e.student_id
and sub.subject_name = e.subject_name
group by s1.student_id, s1.student_name, sub.subject_name
order by s1.student_id,sub.subject_name
