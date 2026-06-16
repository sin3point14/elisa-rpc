#pragma once

#include <map>
#include <string>
#include <thread>

#include <gio/gio.h>

#include "discord.hpp"

class MetadataHandler {
  public:
    MetadataHandler(Discord* rpc);

    Discord* GetRPC();
    void Destroy();
    void LoadProperties();
    void OnPropertiesUpdated();
    void Tick();

    GDBusProxy* properties;

    bool is_playing;
    int64_t accumulated_seconds;
    int64_t current_loop_count;
    std::string current_track_id;
    std::chrono::steady_clock::time_point last_tick_time;

  private:
    GDBusProxy* player;

    GMainLoop* gloop;
    GError* error;

    std::unique_ptr<Discord> rpc;
    std::thread* loop;
};