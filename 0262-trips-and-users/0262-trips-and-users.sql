# Write your MySQL query statement below
SELECT 
t.request_at as Day,
    Round(
        AVG(
            CASE
                WHEN t.status != 'completed' THEN 1.0
                ELSE 0
            END
        ),2
    ) as 'Cancellation Rate'
FROM Trips t
JOIN Users c
ON t.client_id = c.users_id
join Users d
on t.driver_id = d.users_id
where c.banned = 'No'
    and d.banned = 'No'
    and t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at;