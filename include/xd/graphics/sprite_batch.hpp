#ifndef H_XD_GRAPHICS_SPRITE_BATCH
#define H_XD_GRAPHICS_SPRITE_BATCH

#include <xd/graphics/vertex_batch.hpp>
#include <xd/graphics/shader_program.hpp>
#include <xd/graphics/transform_geometry.hpp>
#include <xd/graphics/texture.hpp>
#include <xd/graphics/types.hpp>
#include <xd/vendor/glm/glm.hpp>
#include <boost/noncopyable.hpp>
#include <boost/optional.hpp>

namespace xd
{
	// sprite batch
	class XD_API sprite_batch : public xd::ref_counted, public boost::noncopyable
	{
	public:
		typedef boost::intrusive_ptr<sprite_batch> ptr;

		sprite_batch(xd::transform_geometry& geometry_pipeline);
		virtual ~sprite_batch();

		void clear();
		void draw();

		void add(xd::texture::ptr texture, float x, float y);
		void add(xd::texture::ptr texture, float x, float y, float rotation, float scale);
		void add(xd::texture::ptr texture, float x, float y, float rotation, const glm::vec2& scale);
		void add(xd::texture::ptr texture, float x, float y, const xd::rect& src);
		void add(xd::texture::ptr texture, float x, float y, const xd::rect& src, float rotation, const glm::vec2& anchor, float scale);
		void add(xd::texture::ptr texture, float x, float y, const xd::rect& src, float rotation, const glm::vec2& anchor, const glm::vec2& scale);

	private:
		xd::transform_geometry& m_geometry_pipeline;
	};
}

#endif
