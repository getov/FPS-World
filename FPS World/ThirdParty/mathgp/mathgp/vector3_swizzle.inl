_type& z()
{
    return this->at(2);
}

const _type& z() const
{
    return this->at(2);
}

vector2t<_type>& yz()
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array() + 1);
}

const vector2t<_type>& yz() const
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array() + 1);
}

vector3t<_type>& xyz()
{
    return *reinterpret_cast<vector3t<_type>*>(this->as_array());
}

const vector3t<_type>& xyz() const
{
    return *reinterpret_cast<vector3t<_type>*>(this->as_array());
}
