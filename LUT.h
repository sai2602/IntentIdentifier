#include "std_includes.h"

/*This class acts as the look up table (mimicking the data:label pair of datasets) with a map storing the key:value pair
* and methods to operate on this map
*/
class LUT {
protected:
	LUT_Type LUT_Members;
	void extract_keys(Keys_Values_type* local_keys_vector);

public:
	void Add_to_LUT(str Key, str Value);
	Keys_Values_type Search_SubString(str mainstring);
	int Number_of_Entries();
};
