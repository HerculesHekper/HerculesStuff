CREATE VIEW vw_libertyrostats AS
SELECT
	(SELECT COUNT(`account_id`) FROM `login`) AS `Account_nb`
	,(SELECT COUNT(`char_id`) FROM `char`) AS `Character_nb`
	,(SELECT COUNT(`guild_id`) FROM `guild`) AS `Guild_nb`
	,(ifnull(`inventory_amnt`, 0) 
	+ ifnull(`inventory_slotted0`, 0) 
	+ ifnull(`inventory_slotted1`, 0) 
	+ ifnull(`inventory_slotted2`, 0)
	+ ifnull(`inventory_slotted3`, 0)
	+ ifnull(`storage_slotted0`, 0)
	+ ifnull(`storage_slotted1`, 0)
	+ ifnull(`storage_slotted2`, 0)
	+ ifnull(`storage_slotted3`, 0)
	+ ifnull(`storage_amnt`, 0)
	) AS `Card_nb` FROM vw_cardnb_intermedia1
;
