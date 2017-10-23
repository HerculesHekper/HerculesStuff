SELECT 
  ac.`atcommand_date`
  ,ac.`account_id`
  ,ac.`char_id`
  ,ac.`char_name`
  ,l.`group_id`
  ,ac.`map`
  ,ac.`command` 
FROM `atcommandlog` ac
LEFT JOIN `login` l ON l.`account_id` = ac.`account_id`
WHERE
	l.`group_id` >= 30 -- to filter out regular users
	AND ac.`command` LIKE "@item%" -- Or any other command you are interested in
ORDER BY ac.`atcommand_id` DESC -- sorts to display latest on the top
LIMIT 200; -- Remove Limit for the COMPLETE listing
