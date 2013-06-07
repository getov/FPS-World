_type& w()
{
    return this->at(3);
}

const _type& w() const
{
    return this->at(3);
}

vector2t<_type>& zw()
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array() + 2);
}

const vector2t<_type>& zw() const
{
    return *reinterpret_cast<vector2t<_type>*>(this->as_array() + 2);
}

vector3t<_type>& yzw()
{
    return *reinterpret_cast<vector3t<_type>*>(this->as_array() + 1);
}

const vector3t<_type>& yzw() const
{
    return *reinterpret_cast<vector3t<_type>*>(this->as_array() + 1);
}

vector4t<_type>& xyzw()
{
    return *reinterpret_cast<vector4t<_type>*>(this->as_array());
}

const vector4t<_type>& xyzw() const
{
    return *reinterpret_cast<vector4t<_type>*>(this->as_array());
}
