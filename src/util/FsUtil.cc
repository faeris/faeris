size_t Util_JStringHashCode(const char* str)
{
	size_t hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return hash ;
}
