#pragma once

#include "GLConfig.h"
#include "MatrixConfig.h"
#include "GLTexture.h"
#include <functional>
#include <unordered_map>
#include <string>

namespace tezcat
{
	class UniformBaseValue
	{
	public:
		enum class ValueType : char
		{
			BOOL = 0,
			UINT,
			INT,
			FLOAT,
			TEXTURE
		};

		enum class ValueCount : char
		{
			C1,C2,C3,C4
		};

	public:
		UniformBaseValue(const ValueType &type, const ValueCount &count) : m_Type(type), m_Count(count), m_Location(-1) {}
		virtual ~UniformBaseValue() {}

		const ValueType &getValueType() const { return m_Type; }
		const ValueCount &getValueCount() const { return m_Count; }
		void setLocation(const int &location) { m_Location = location; }

		virtual void upload() = 0;

	protected:
		ValueType m_Type;
		ValueCount m_Count;
		int m_Location;
	};

	class UniformValue1 : public UniformBaseValue
	{
	public:
		UniformValue1(const ValueType &type):i(0), UniformBaseValue(type, ValueCount::C1){}
		UniformValue1(const bool &value) : b(value), UniformBaseValue(ValueType::BOOL, ValueCount::C1) {}
		UniformValue1(const unsigned int &value) : ui(value), UniformBaseValue(ValueType::UINT, ValueCount::C1) {}
		UniformValue1(const int &value) : i(value), UniformBaseValue(ValueType::INT, ValueCount::C1) {}
		UniformValue1(const float &value) :	f(value), UniformBaseValue(ValueType::FLOAT, ValueCount::C1) {}

		const bool &getBool() const { return b; }
		const unsigned int &getUInt() const { return ui; }
		const int &getInt() const { return i; }
		const float &getFloat() const { return f; }

		void setBool(const bool &value) { b = value; }
		void setUInt(const unsigned int &value) { ui = value; }
		void setInt(const int &value) { i = value; }
		void setFloat(const float &value) { f = value; }

		void upload()
		{
			switch (m_Type)
			{
			case UniformBaseValue::ValueType::BOOL:
				glUniform1i(m_Location, b);
				break;
			case UniformBaseValue::ValueType::INT:
				glUniform1i(m_Location, i);
				break;
			case UniformBaseValue::ValueType::UINT:
				glUniform1ui(m_Location, ui);
				break;
			case UniformBaseValue::ValueType::FLOAT:
				glUniform1f(m_Location, f);
				break;
			}
		}

	private:
		union
		{
			bool b;
			unsigned int ui;
			int i;
			float f;
		};
	};

	class UniformValue2 : public UniformBaseValue
	{
	public:
		struct Value
		{
			Value() : i1(0), i2(0) {}
			Value(const bool &value1, const bool &value2) : b1(value1), b2(value2) {}
			Value(const unsigned int &value1, const unsigned int &value2) : ui1(value1), ui2(value2) {}
			Value(const int &value1, const int &value2) : i1(value1), i2(value2) {}
			Value(const float &value1, const float &value2) : f1(value1), f2(value2) {}

			union
			{
				bool b1;
				unsigned int ui1;
				int i1;
				float f1;
			};

			union
			{
				bool b2;
				unsigned int ui2;
				int i2;
				float f2;
			};
		};

	public:
		UniformValue2(const ValueType &type) : UniformBaseValue(type, ValueCount::C2) {}

		UniformValue2(const bool &value1, const bool &value2):
			m_Value(value1, value2), UniformBaseValue(ValueType::BOOL, ValueCount::C2) {}
		UniformValue2(const unsigned int &value1, const unsigned int &value2):
			m_Value(value1, value2), UniformBaseValue(ValueType::UINT, ValueCount::C2) {}
		UniformValue2(const int &value1, const int &value2):
			m_Value(value1, value2), UniformBaseValue(ValueType::INT, ValueCount::C2) {}
		UniformValue2(const float &value1, const float &value2):
			m_Value(value1, value2), UniformBaseValue(ValueType::FLOAT, ValueCount::C2) {}

		const Value &getValue() const { return m_Value; }

		void setBool(const bool &value1, const bool &value2)
		{
			m_Value.b1 = value1; m_Value.b2 = value2;
		}
		void setUInt(const unsigned int &value1, const unsigned int &value2)
		{
			m_Value.ui1 = value1; m_Value.ui2 = value2;
		}
		void setInt(const int &value1, const int &value2)
		{
			m_Value.i1 = value1; m_Value.i2 = value2;
		}
		void setFloat(const float &value1, const float &value2)
		{
			m_Value.f1 = value1; m_Value.f2 = value2;
		}

		void upload()
		{
			switch (m_Type)
			{
			case UniformBaseValue::ValueType::BOOL:
				glUniform2i(m_Location, m_Value.b1, m_Value.b2);
				break;
			case UniformBaseValue::ValueType::INT:
				glUniform2i(m_Location, m_Value.i1, m_Value.i2);
				break;
			case UniformBaseValue::ValueType::UINT:
				glUniform2ui(m_Location, m_Value.ui1, m_Value.ui2);
				break;
			case UniformBaseValue::ValueType::FLOAT:
				glUniform2f(m_Location, m_Value.f1, m_Value.f2);
				break;
			}
		}

	private:
		Value m_Value;
	};

	//===========================================================================
	//
	//	U3
	//
	class UniformValue3 : public UniformBaseValue
	{
	public:
		struct Value
		{
			Value() : i1(0), i2(0), i3(0) {}
			Value(const bool &value1, const bool &value2, const bool &value3):
				b1(value1), b2(value2), b3(value3) {}
			Value(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3):
				ui1(value1), ui2(value2), ui3(value3) {}
			Value(const int &value1, const int &value2, const int &value3):
				i1(value1), i2(value2), i3(value3) {}
			Value(const float &value1, const float &value2, const float &value3):
				f1(value1), f2(value2), f3(value3) {}

			union
			{
				bool b1;
				unsigned int ui1;
				int i1;
				float f1;
			};

			union
			{
				bool b2;
				unsigned int ui2;
				int i2;
				float f2;
			};

			union
			{
				bool b3;
				unsigned int ui3;
				int i3;
				float f3;
			};
		};

	public:
		UniformValue3(const ValueType &type) : UniformBaseValue(type, ValueCount::C3) {}

		UniformValue3(const bool &value1, const bool &value2, const bool &value3):
			m_Value(value1, value2, value3), UniformBaseValue(ValueType::BOOL, ValueCount::C3) {}
		UniformValue3(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3):
			m_Value(value1, value2,value3), UniformBaseValue(ValueType::UINT, ValueCount::C3) {}
		UniformValue3(const int &value1, const int &value2, const int &value3):
			m_Value(value1, value2, value3), UniformBaseValue(ValueType::INT, ValueCount::C3) {}
		UniformValue3(const float &value1, const float &value2, const float &value3):
			m_Value(value1, value2, value3), UniformBaseValue(ValueType::FLOAT, ValueCount::C3) {}

		const Value &getValue() const { return m_Value; }

		void setBool(const bool &value1, const bool &value2, const bool &value3)
		{
			m_Value.b1 = value1; m_Value.b2 = value2; m_Value.b3 = value3;
		}
		void setUInt(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3)
		{
			m_Value.ui1 = value1; m_Value.ui2 = value2; m_Value.ui3 = value3;
		}
		void setInt(const int &value1, const int &value2, const int &value3)
		{
			m_Value.i1 = value1; m_Value.i2 = value2; m_Value.i3 = value3;
		}
		void setFloat(const float &value1, const float &value2, const float &value3)
		{
			m_Value.f1 = value1; m_Value.f2 = value2; m_Value.f3 = value3;
		}

		void upload()
		{
			switch (m_Type)
			{
			case UniformBaseValue::ValueType::BOOL:
				glUniform3i(m_Location, m_Value.b1, m_Value.b2, m_Value.b3);
				break;
			case UniformBaseValue::ValueType::INT:
				glUniform3i(m_Location, m_Value.i1, m_Value.i2, m_Value.i3);
				break;
			case UniformBaseValue::ValueType::UINT:
				glUniform3ui(m_Location, m_Value.ui1, m_Value.ui2, m_Value.ui3);
				break;
			case UniformBaseValue::ValueType::FLOAT:
				glUniform3f(m_Location, m_Value.f1, m_Value.f2, m_Value.f3);
				break;
			}
		}

	private:
		Value m_Value;
	};

	//===========================================================================
	//
	//	U4
	//
	class UniformValue4 : public UniformBaseValue
	{
	public:
		struct Value
		{
			Value() : i1(0), i2(0), i3(0), i4(0) {}
			Value(const bool &value1, const bool &value2, const bool &value3, const bool &value4) :
				b1(value1), b2(value2), b3(value3), b4(value4) {}
			Value(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4) :
				ui1(value1), ui2(value2), ui3(value3), ui4(value4) {}
			Value(const int &value1, const int &value2, const int &value3, const int &value4) :
				i1(value1), i2(value2), i3(value3), i4(value4) {}
			Value(const float &value1, const float &value2, const float &value3, const float &value4) :
				f1(value1), f2(value2), f3(value3), f4(value4) {}

			union
			{
				bool b1;
				unsigned int ui1;
				int i1;
				float f1;
			};

			union
			{
				bool b2;
				unsigned int ui2;
				int i2;
				float f2;
			};

			union
			{
				bool b3;
				unsigned int ui3;
				int i3;
				float f3;
			};

			union
			{
				bool b4;
				unsigned int ui4;
				int i4;
				float f4;
			};
		};

	public:
		UniformValue4(const ValueType &type) : UniformBaseValue(type, ValueCount::C4) {}

		UniformValue4(const bool &value1, const bool &value2, const bool &value3, const bool &value4):
			m_Value(value1, value2, value3, value4), UniformBaseValue(ValueType::BOOL, ValueCount::C4) {}
		UniformValue4(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4):
			m_Value(value1, value2, value3, value4), UniformBaseValue(ValueType::UINT, ValueCount::C4) {}
		UniformValue4(const int &value1, const int &value2, const int &value3, const int &value4):
			m_Value(value1, value2, value3, value4), UniformBaseValue(ValueType::INT, ValueCount::C4) {}
		UniformValue4(const float &value1, const float &value2, const float &value3, const float &value4):
			m_Value(value1, value2, value3, value4), UniformBaseValue(ValueType::FLOAT, ValueCount::C4) {}

		const Value &getValue() const { return m_Value; }

		void setBool(const bool &value1, const bool &value2, const bool &value3, const bool &value4)
		{
			m_Value.b1 = value1; m_Value.b2 = value2; m_Value.b3 = value3; m_Value.b4 = value4;
		}

		void setUInt(const unsigned int &value1, const unsigned int &value2, const unsigned int &value3, const unsigned int &value4)
		{
			m_Value.ui1 = value1; m_Value.ui2 = value2; m_Value.ui3 = value3; m_Value.ui4 = value4;
		}

		void setInt(const int &value1, const int &value2, const int &value3, const int &value4)
		{
			m_Value.i1 = value1; m_Value.i2 = value2; m_Value.i3 = value3; m_Value.i4 = value4;
		}

		void setFloat(const float &value1, const float &value2, const float &value3, const float &value4)
		{
			m_Value.f1 = value1; m_Value.f2 = value2; m_Value.f3 = value3; m_Value.f1 = value4;
		}

		void upload()
		{
			switch (m_Type)
			{
			case UniformBaseValue::ValueType::BOOL:
				glUniform4i(m_Location, m_Value.b1, m_Value.b2, m_Value.b3, m_Value.b4);
				break;
			case UniformBaseValue::ValueType::INT:
				glUniform4i(m_Location, m_Value.i1, m_Value.i2, m_Value.i3, m_Value.i4);
				break;
			case UniformBaseValue::ValueType::UINT:
				glUniform4ui(m_Location, m_Value.ui1, m_Value.ui2, m_Value.ui3, m_Value.ui4);
				break;
			case UniformBaseValue::ValueType::FLOAT:
				glUniform4f(m_Location, m_Value.f1, m_Value.f2, m_Value.f3, m_Value.f4);
				break;
			}
		}

	private:
		Value m_Value;
	};

	class UniformValueWithTexture : public UniformBaseValue
	{
	public:
		UniformValueWithTexture(GLTexture *texture, const unsigned int &index, const ValueCount &count):
			m_Texture(texture), m_Index(index), UniformBaseValue(ValueType::TEXTURE, count) {}
		UniformValueWithTexture(const ValueCount &count):
			m_Texture(nullptr), m_Index(0), UniformBaseValue(ValueType::TEXTURE, count) {}

		void upload()
		{
			if (m_Texture)
			{
				m_Texture->bind(m_Index, m_Location);
			}
		}

		void setTextureName(const std::string &name)
		{
			m_Name = name;
		}
		
		const std::string &getTextureName() const { return m_Name; }

		void setTexture(GLTexture *tex, const unsigned int &index)
		{ 
			m_Texture = tex; m_Index = index;
		}

	private:
		unsigned int m_Index;
		GLTexture *m_Texture;
		std::string m_Name;
	};

	typedef std::unordered_map<std::string, UniformBaseValue *> UniformBaseProperty;
}