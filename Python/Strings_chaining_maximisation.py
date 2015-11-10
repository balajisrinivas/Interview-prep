
def is_round(str1, str2):
	len1 = len(str1)
	len2 = len(str2)
	i, j = 0, 0
	flag = 0
	while i < len1 and j < len2:
		if str1[i] == str2[j]:
			i = i + 1
			j = j + 1
		else:
			if flag == 0:
				i = i + 1
				flag = 1
			else:
				return 0
	return 1;

def update_rounds_map(str1, str2, rounds_map):
	is_round_possible = is_round(str1, str2)
	if is_round_possible == 1:
		local_rounds = rounds_map[str2] + 1
		if local_rounds > rounds_map[str1]:
			rounds_map[str1] = local_rounds

def maximum_rounds(input):
	length_map = {}
	for string in input:
		key = len(string)
		if key in length_map:
			value = length_map[key]
			value.append(string)
		else:
			list = []
			list.append(string)
			length_map[key] = list
	rounds_map = {}
	for string in input:
		rounds_map[string] = 0

	length_keys = length_map.keys()
	length_keys.sort()

	for i in range(1, len(length_keys)):
		len1 = length_keys[i]
		len2 = length_keys[i-1]
		if len1 != len2 + 1:
			continue
		for str1 in length_map[len1]:
			for str2 in length_map[len2]:
				update_rounds_map(str1, str2, rounds_map)
	print rounds_map

	max_key = ""
	max_value = 0
	for key, value in rounds_map.iteritems():
		if value > max_value:
			max_key = key
			max_value = value

	print max_key, max_value


input = ["bdca", "a", "ba", "b"]
maximum_rounds(input)
