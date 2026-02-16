SELECT  user_id,
        action,
        COUNT(action) AS streak_length,
        MIN(action_date) AS start_date,
        MAX(action_date) AS end_date 
FROM activity
GROUP BY user_id, action
HAVING COUNT(action) >= 5
ORDER BY streak_length DESC, user_id ASC;