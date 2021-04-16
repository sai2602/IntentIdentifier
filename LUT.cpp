#include "LUT.h"

/*This method adds the new key:value pair to the map (look up table)
* @params: string (Key), string (Value)
* @return: none
*/
void LUT::Add_to_LUT(str Key, str Value) {
	LUT_Members[Key] = Value;
}

/*This method checks if a ceratin key from the map is present in the input string
* @params: string (input string)
* @return: Vector (all the values corresponding to the keys found in the string stored in a vector)
*/
Keys_Values_type LUT::Search_SubString(str mainstring) {
	Keys_Values_type keys, values;
	extract_keys(&keys);

	for (str each_key : keys) {
		if (mainstring.find(each_key) != str::npos) {
			values.push_back(LUT_Members[each_key]);
		}
	}

	return values;
}

/*This method extracts all the keys from the map and stores them in a vector
* @params: pointer to a local copy of the vector
* @return: none
*/
void LUT::extract_keys(Keys_Values_type* local_keys_vector) {
	for (LUT_Type::iterator it = LUT_Members.begin(); it != LUT_Members.end(); ++it) {
		local_keys_vector->push_back(it->first);
	}
	
}

/*This method returns the number of entries in the map (look up table)
* @params: none
* @return: int (number of entries)
*/
int LUT::Number_of_Entries() {
	return LUT_Members.size();
}