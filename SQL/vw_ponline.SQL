CREATE VIEW vw_ponline AS
SELECT 
C.`account_id`
,C.`char_id`
,L.`group_id`
,C.`name`
,C.`class`
,C.`base_level`
,C.`job_level`
,C.`base_exp`
,C.`job_exp`
,C.`zeny`
,L.last_ip
,L.lastlogin
FROM `char` C
LEFT JOIN `login` L ON C.account_id=L.account_id
WHERE `online` > 0;
