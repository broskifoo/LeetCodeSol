# Write your MySQL query statement below
SELECT 
    d.name as department,
    e1.name as Employee,
    e1.salary as Salary
from Employee e1
join Department d 
on e1.departmentId = d.id
left join employee e2
on e1.departmentId = e2.departmentId
and e2.salary > e1.salary
group by e1.id , d.name , e1.name, e1.salary
having count(distinct e2.salary) < 3;