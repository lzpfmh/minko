#pragma once

#include "minko/Common.hpp"

namespace minko
{
	namespace render
	{
		using namespace minko::render::context;

		class ShaderProgramInputs :
			public std::enable_shared_from_this<ShaderProgramInputs>
		{
		public:
			typedef std::shared_ptr<ShaderProgramInputs>	ptr;

			enum Type
			{
				unknown,
				int1,
				int2,
				int3,
				int4,
				float1,
				float2,
				float3,
				float4,
				float9,
				float16,
				sampler2d,
				attribute
			};

		public:
			static
			ptr
			create(std::shared_ptr<AbstractContext>	context,
				   const unsigned int 				program,
				   std::vector<std::string> 		names,
				   std::vector<Type> 				types,
				   std::vector<unsigned int> 		locations)
			{
				return std::shared_ptr<ShaderProgramInputs>(new ShaderProgramInputs(
					context,
					program,
					names,
					types,
					locations
				));
			}

			static
			std::string
			typeToString(const Type type)
			{
				switch (type)
				{
					case Type::unknown:
						return "unknown";
					case Type::int1:
						return "int1";
					case Type::int2:
						return "int2";
					case Type::int3:
						return "int3";
					case Type::int4:
						return "int4";
					case Type::float1:
						return "float1";
					case Type::float2:
						return "float2";
					case Type::float3:
						return "float3";
					case Type::float4:
						return "float4";
					case Type::float9:
						return "float9";
					case Type::float16:
						return "float16";
					default:
						throw std::invalid_argument("type");
				}
			}

		public:
			inline
			const std::vector<std::string>&
			names()
			{
				return _names;
			}

			inline
			const std::vector<Type>&
			types()
			{
				return _types;
			}

			inline
			const std::vector<unsigned int>&
			locations()
			{
				return _locations;
			}

		private:
			std::shared_ptr<AbstractContext>	_context;
			const unsigned int 					_program;
			std::vector<std::string>			_names;
			std::vector<Type> 					_types;
			std::vector<unsigned int>			_locations;

		private:
			ShaderProgramInputs(std::shared_ptr<AbstractContext>	context,
								const unsigned int 					program,
								std::vector<std::string> 			names,
						 		std::vector<Type> 					types,
						 		std::vector<unsigned int> 			locations) :
				std::enable_shared_from_this<ShaderProgramInputs>(),
				_context(context),
				_program(program),
				_names(names),
				_types(types),
				_locations(locations)
			{
			}
		};
	}
}
