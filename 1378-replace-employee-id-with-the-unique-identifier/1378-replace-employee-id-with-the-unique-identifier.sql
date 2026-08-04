# Write your MySQL query statement below
select E.unique_id, Ey.name from Employees as Ey 
left join EmployeeUNI as E
on Ey.id = E.id
