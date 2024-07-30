/*****************************************************************************
 * Copyright (C) 2021 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * ( at your option ) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef MLPLAYLISTMEDIA_H
#define MLPLAYLISTMEDIA_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

// MediaLibrary includes
#include "mlmedia.hpp"

// NOTE: We need that header for VideoDescription and AudioDescription.
#include "mlvideo.hpp"

class VLCTick;

// Qt includes
#include <QUrl>

// Forward declarations
struct vlc_medialibrary_t;

class MLPlaylistMedia : public MLMedia
{
public:
    MLPlaylistMedia( const vlc_ml_media_t * data);

public: // Interface
    bool isNew() const;

    vlc_ml_media_type_t getType() const;

    void setSmallCover(const QString& thumbnail, vlc_ml_thumbnail_status_t status);

    QString getResolutionName() const;

    QString getChannel() const;

    QString getMRL       () const;
    QString getMRLDisplay() const;

    QList<VideoDescription> getVideo() const;
    QList<AudioDescription> getAudio() const;


private: // Events
    static void onMlEvent(void * data, const vlc_ml_event_t * event);

    void onMlEvent(const vlc_ml_event_t * event);

private:
    // Properties
    vlc_ml_media_type_t m_type;

    QString m_resolution;
    QString m_channel;
    QUrl m_mrl;
    QList<VideoDescription> m_video;
    QList<AudioDescription> m_audio;
};

#endif // MLPLAYLISTMEDIA_H
