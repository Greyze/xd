#ifndef H_XD_AUDIO_MUSIC
#define H_XD_AUDIO_MUSIC

#include <xd/config.hpp>
#include <xd/handle.hpp>
#include <boost/noncopyable.hpp>
#include <string>

#pragma warning(disable: 4275)

namespace xd
{
	namespace detail
	{
		struct music_handle;
	}

	class XD_API music : public boost::noncopyable
	{
	public:
		typedef handle<music> handle;
		typedef weak_handle<music> weak_handle;

		music(const std::string& filename);
		virtual ~music();

		void play();
		void pause();
		void stop();

		bool playing() const;
		bool paused() const;
		bool stopped() const;

		void set_offset(float offset);
		void set_volume(float volume);
		void set_pitch(float pitch);
		void set_looping(bool looping);
		void set_loop_point(float time);

		float get_offset() const;
		float get_volume() const;
		float get_pitch() const;
		bool get_looping() const;
		float get_loop_point() const;

	private:
		detail::music_handle *m_handle;
	};
}

#endif
