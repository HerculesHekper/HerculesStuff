/*
Example of the SQL query that would summ the guildmate's variable and 
sort guilds to provide a top 10
ATTENTION : As Variables are stored as a whole in Herc database, if character quits current guild and joins another guild, the variable is not resetted.
*/

SELECT 
SUM(`char_reg_num_db`.value) AS `NB_VAR`
,`guild`.`guild_id`
,`guild`.`Name`
FROM `char_reg_num_db`
LEFT JOIN `char` ON `char`.`char_id`=`char_reg_num_db`.`char_id`
LEFT JOIN `guild` ON `guild`.`guild_id`=`char`.`guild_id`
WHERE `char_reg_num_db`.`key`='PC_DIE_COUNTER' && `char`.`guild_id` <> 0
GROUP BY `char`.`guild_id`
ORDER BY NB_VAR DESC
LIMIT 10;
